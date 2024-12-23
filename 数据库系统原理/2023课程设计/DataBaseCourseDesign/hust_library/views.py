from django.http import Http404,HttpResponse
from django.shortcuts import render, redirect, get_object_or_404
from django.views import generic
from django.contrib.auth.models import User, Group
from django.contrib.auth.decorators import login_required, permission_required
from django.contrib import messages
from django.utils.decorators import method_decorator
from .models import Ticket, Book, Store, Write, Loan
from . import func, forms
from django.utils import timezone
import json

# Create your views here.


def index_view(request):
    if request.user.is_authenticated:
        if Group.objects.get(name='Administrators') in request.user.groups.all():
            return redirect('administrator')
    return render(request, 'index.html')


@login_required
def is_admin_view(request):
    if Group.objects.get(name='Readers') in request.user.groups.all():
        return redirect('index')
    else:
        return redirect('/administrator/')


@login_required
def self_inf_view(request):
    return render(request, 'self_inf.html')


@login_required
def loans_view(request):
    context = {"is_empty": False, "loans": None}
    loans = Loan.objects.filter(
        reader__id=request.user.id).order_by('-time')
    context["loans"] = loans
    if loans.count() == 0:
        context["is_empty"] = True
    return render(request, 'loans.html', context)


@login_required
def loaned_view(request):
    context = {"is_empty": False, "loaned": None}
    loans = Loan.objects.filter(
        reader__id=request.user.id).order_by('-time')
    loaned = func.get_loaned(loans)
    context["loaned"] = loaned
    if len(loaned) == 0:
        context["is_empty"] = True
    return render(request, 'loaned.html', context)


@login_required
@permission_required('hust_library.add_loan')
def renew_view(request, pk):
    try:
        loan = Loan.objects.get(id=pk, reader__id=request.user.id)
    except:
        messages.error(request, '借书单号无效')
    else:
        out_date = (timezone.now()-loan.time).days > 30
        wrong_loan = Loan.objects.filter(
            store__id=loan.store.id).order_by('-time')[0].id != loan.id
        if loan.state != 0 or out_date or wrong_loan:
            messages.error(request, '无法续借')
        else:
            renew = Loan(time=timezone.now(), state=2,
                         store=loan.store, reader=loan.reader)
            renew.save()
            messages.success(request, '续借成功')

    return redirect('loaned')


@login_required
def tickets_view(request):
    context = {"is_empty": False, "tickets": None}
    tickets = Ticket.objects.filter(
        reader__id=request.user.id).order_by('-time')
    context["tickets"] = tickets
    if tickets.count() == 0:
        context["is_empty"] = True
    return render(request, 'tickets.html', context)


@login_required
def ticket_handle_view(request, pk):
    try:
        ticket = Ticket.objects.get(id=pk, reader__id=request.user.id)
    except:
        messages.error(request, '罚单号无效')
    else:
        if ticket.state != 0:
            messages.error(request, '罚单已完成')
        else:
            ticket.state = 1
            ticket.save()
            messages.success(request, '操作成功')

    return redirect('tickets')


@login_required
def books_view(request):
    context = {"is_empty": False, "books": None}
    if 'name' in request.GET:
        name = request.GET['name']
        books = Book.objects.filter(name__contains=name).order_by('-time')
        context['books'] = books
        if books.count() == 0:
            context['is_empty'] = True

    return render(request, 'books.html', context)


@method_decorator(login_required, name='dispatch')
class BookView(generic.DetailView):
    model = Book
    template_name = 'book.html'


@login_required
def administrator_view(request):
    if Group.objects.get(name='Readers') in request.user.groups.all():
        return redirect('index')
    return render(request, 'administrator.html')


@login_required
@permission_required('hust_library.add_loan')
def borrow_manage_view(request):
    if request.method == 'POST':
        form = forms.BorrowManageForm(request.POST)
        if form.is_valid():
            try:
                store = Store.objects.get(id=form.cleaned_data['store_id'])
                reader = User.objects.get(
                    username=form.cleaned_data['username'])
            except:
                messages.error(request, '藏书号或用户名不存在')
            else:
                if store.state == 0:
                    messages.error(request, '书籍不在馆')
                elif store.state == 2:
                    messages.error(request, '书籍已损坏')
                else:
                    loans = Loan.objects.filter(
                        reader__id=reader.id).order_by('-time')
                    loaned = func.get_loaned(loans)
                    if len(loaned) > 4:
                        messages.error(request, '不能借书超过4本')
                    else:
                        can_borrow = True
                        for loan in loaned:
                            if loan['remain'] < 0:
                                messages.error(
                                    request, '请先处理超时未还书籍：' + loan['loan'].store.book.name)
                                can_borrow = False
                                break
                        if can_borrow:
                            for ticket in Ticket.objects.filter(reader__id=reader.id):
                                if ticket.state == 0:
                                    messages.error(
                                        request, '请先处理罚单：' + ticket.description)
                                    can_borrow = False
                                    break
                            if can_borrow:
                                store.state = 0
                                store.save()
                                borrow = Loan(
                                    time=timezone.now(), state=0, store=store, reader=reader)
                                borrow.save()
                                messages.success(request, '借阅成功')
    else:
        form = forms.BorrowManageForm()
    return render(request, 'borrow_manage.html', {'form': form})


@login_required
@permission_required('hust_library.add_loan')
def return_manage_view(request):
    if request.method == 'POST':
        form = forms.ReturnManageForm(request.POST)
        if form.is_valid():
            try:
                store = Store.objects.get(id=form.cleaned_data['store_id'])
            except:
                messages.error(request, '藏书号不存在')
            else:
                is_broken = form.cleaned_data['is_broken']
                if store.state == 1:
                    messages.error(request, '书籍在馆')
                elif store.state == 2:
                    messages.error(request, '书籍损坏')
                else:
                    borrow_loan = store.loan_set.all().order_by('-time')[0]
                    return_loan = Loan(
                        time=timezone.now(), state=1, store=store, reader=borrow_loan.reader)
                    return_loan.save()
                    remian = (borrow_loan.time - return_loan.time).days + 30
                    price = 0
                    description = ''
                    if is_broken:
                        store.state = 2
                        store.save()
                        price = store.book.price
                        description = "藏书号:%d 书名:%s 损坏" % (
                            store.id, store.book.name)
                    elif remian < 0:
                        store.state = 0
                        store.save()
                        price = -remian if remian > -100 else 100
                        description = "藏书号:%d 书名:%s 逾期归还:%d天" % (
                            store.id, store.book.name, -remian)
                    else:
                        store.state = 0
                        store.save()
                    if price > 0:
                        ticket = Ticket(price=price, time=timezone.now(
                        ), state=0, description=description, reader=borrow_loan.reader)
                        ticket.save()
                        messages.success(request, '还书成功，生成罚单')
                    else:
                        messages.success(request, '还书成功')

    else:
        form = forms.ReturnManageForm()
    return render(request, 'return_manage.html', {'form': form})


@login_required
@permission_required('hust_library.add_book')
def books_manage_view(request):
    context = {"is_empty": False, "books": None}
    if 'name' in request.GET:
        name = request.GET['name']
        books = Book.objects.filter(name__contains=name).order_by('-time')
        context['books'] = books
        if books.count() == 0:
            context['is_empty'] = True

    return render(request, 'books_manage.html', context)


@login_required
@permission_required('hust_library.change_book')
def book_manage_view(request, pk):
    book = get_object_or_404(Book, id=pk)
    form = forms.BookForm(instance=book)
    return render(request, 'book_manage.html', {'book': book, 'form': form})


@login_required
@permission_required('hust_library.add_book')
def new_book_view(request):
    if request.method == 'POST':
        form = forms.BookForm(request.POST)
        if form.is_valid():
            try:
                book = form.save(commit=False)
                book.save()
            except:
                messages.error(request, '已有属性完全一致的书籍')
            else:
                messages.success(request, '新建成功')
                return redirect('book_manage',pk=book.id)
    else:
        form = forms.BookForm()
    return render(request, 'new_book.html', {'form': form})


@login_required
@permission_required('hust_library.change_book')
def edit_book_view(request, pk):
    if request.method == 'POST':
        try:
            book = Book.objects.get(id=pk)
            form = forms.BookForm(request.POST, instance=book)
        except:
            messages.error(request, '书籍id不存在')
        else:
            if form.is_valid():
                try:
                    form.save()
                except:
                    messages.error(request, '已有属性完全一致的书籍')
                else:
                    messages.success(request, '修改成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('book_manage', pk=pk)


@login_required
@permission_required('hust_library.delete_book')
def delete_book_view(request, pk):
    try:
        book = Book.objects.get(id=pk)
    except:
        messages.error(request, '书籍id不存在')
    else:
        book.delete()
        messages.success(request, '删除成功')
    return redirect('books_manage')

@login_required
@permission_required('hust_library.add_write')
def write_view(request, book_pk):
    writes=[]
    try:
        book = Book.objects.get(id=book_pk)
    except:
        messages.error(request, '书籍id不存在')
    else:
        for write in book.write_set.all():
            writes.append({"state":False,"id":write.id,"writer":write.writer})
    return HttpResponse(json.dumps(writes))




@login_required
@permission_required('hust_library.add_write')
def new_write_view(request, book_pk):
    if request.method == 'POST':
        try:
            book = Book.objects.get(id=book_pk)
        except:
            messages.error(request, '书籍id不存在')
        else:
            try:
                write = Write(writer=request.POST['writer'], book=book)
                write.save()
            except:
                messages.error(request, '同一本书作者不能重名')
            else:
                messages.success(request, '添加成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('book_manage', pk=book_pk)


@login_required
@permission_required('hust_library.change_write')
def edit_write_view(request, pk):
    if request.method == 'POST':
        try:
            write = Write.objects.get(id=pk)
        except:
            messages.error(request, '著作id不存在')
        else:
            try:
                write.writer = request.POST['writer']
                write.save()
            except:
                messages.error(request, '同一本书作者不能重名')
            else:
                messages.success(request, '修改成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('book_manage', pk=write.book.id)


@login_required
@permission_required('hust_library.delete_write')
def delete_write_view(request, pk):
    try:
        write = Write.objects.get(id=pk)
    except:
        messages.error(request, '著作id不存在')
    else:
        write.delete()
        messages.success(request, '删除成功')
    return redirect('book_manage', pk=write.book.id)


@login_required
@permission_required('hust_library.add_write')
def store_view(request, book_pk):
    stores=[]
    try:
        book = Book.objects.get(id=book_pk)
    except:
        messages.error(request, '书籍id不存在')
    else:
        for store in book.store_set.all():
            state = "在馆"
            if store.state == 0:
                state = "借出"
            elif store.state == 2:
                state="损坏"
            stores.append({"state":False, "id":store.id,"location":store.location,"store_state":state })
    return HttpResponse(json.dumps(stores))


@login_required
@permission_required('hust_library.add_store')
def new_store_view(request, book_pk):
    if request.method == 'POST':
        try:
            book = Book.objects.get(id=book_pk)
        except:
            messages.error(request, '书籍id不存在')
        else:
            try:
                store = Store(
                    location=request.POST['location'], state=1, book=book)
                store.save()
            except:
                messages.error(request, '添加失败')
            else:
                messages.success(request, '添加成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('book_manage', pk=book_pk)


@login_required
@permission_required('hust_library.change_store')
def edit_store_view(request, pk):
    if request.method == 'POST':
        try:
            store = Store.objects.get(id=pk)
        except:
            messages.error(request, '藏书id不存在')
        else:
            try:
                store.location = request.POST['location']
                store.save()
            except:
                messages.error(request, '修改失败')
            else:
                messages.success(request, '修改成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('book_manage', pk=store.book.id)


@login_required
@permission_required('hust_library.delete_store')
def delete_store_view(request, pk):
    try:
        store = Store.objects.get(id=pk)
    except:
        messages.error(request, '藏书id不存在')
    else:
        store.delete()
        messages.success(request, '修改成功')
    return redirect('book_manage', pk=store.book.id)


@login_required
@permission_required('auth.add_user')
def readers_manage_view(request):
    context = {"is_empty": False, "readers": None}
    if 'name' in request.GET:
        name = request.GET['name']
        readers = User.objects.filter(
            username__contains=name, groups__name='Readers').order_by('username')
        context['readers'] = readers
        if readers.count() == 0:
            context['is_empty'] = True

    return render(request, 'readers_manage.html', context)


@login_required
@permission_required('auth.change_user')
def reader_manage_view(request, pk):
    reader = get_object_or_404(User, id=pk)
    if Group.objects.get(name='Readers') in request.user.groups.all():
        raise Http404("用户不存在")
    form = forms.ReaderForm(initial={'username':reader.username, 'first_name':reader.first_name, 'last_name':reader.last_name, 'email':reader.email})
    
    return render(request, 'reader_manage.html', {'reader': reader, 'form': form})


@login_required
@permission_required('auth.add_user')
def new_reader_view(request):
    if request.method == 'POST':
        form = forms.ReaderForm(request.POST)
        if form.is_valid():
            try:
                reader = User(username=form.cleaned_data['username'], first_name=form.cleaned_data['first_name'],
                              last_name=form.cleaned_data['last_name'], email=form.cleaned_data['email'], password='password0')
                reader.save()
            except:
                messages.error(request, '用户名已存在')
            else:
                group = Group.objects.get(name='Readers')
                group.user_set.add(reader)
                group.save()
                messages.success(request, '新建成功')
                return redirect('reader_manage',pk=reader.id)
    else:
        form = forms.ReaderForm()
    return render(request, 'new_Reader.html', {'form': form})


@login_required
@permission_required('auth.change_user')
def edit_reader_view(request, pk):
    if request.method == 'POST':
        try:
            reader = User.objects.get(id=pk)
            if Group.objects.get(name='Readers') in request.user.groups.all():
                raise Http404("用户id不存在")
            form = forms.ReaderForm(request.POST)
        except:
            messages.error(request, '用户id不存在')
        else:
            if form.is_valid():
                try:
                    reader.username = form.cleaned_data['username']
                    reader.first_name = form.cleaned_data['first_name']
                    reader.last_name = form.cleaned_data['last_name']
                    reader.email = form.cleaned_data['email']
                    reader.save()
                except:
                    messages.error(request, '用户名已存在')
                else:
                    messages.success(request, '修改成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('reader_manage', pk=pk)


@login_required
@permission_required('auth.delete_user')
def delete_reader_view(request, pk):
    try:
        reader = User.objects.get(id=pk)
        if Group.objects.get(name='Readers') in request.user.groups.all():
            raise Http404("用户id不存在")
    except:
        messages.error(request, '用户id不存在')
    else:
        reader.delete()
        messages.success(request, '删除成功')
    return redirect('readers_manage')


@login_required
@permission_required('auth.change_user')
def set_password_view(request, pk):
    if request.method == 'POST':
        try:
            reader = User.objects.get(id=pk)
            if Group.objects.get(name='Readers') in request.user.groups.all():
                raise Http404("用户id不存在")
        except:
            messages.error(request, '用户id不存在')
        else:
            password = request.POST['password']
            confirm_password = request.POST['confirm_password']
            if password != confirm_password:
                messages.error(request, '密码与确认密码不一致')
            else:
                reader.set_password(password)
                reader.save()
                messages.success(request, '修改成功')
    else:
        messages.error(request, '此url不能使用post以外方法')
    return redirect('reader_manage',pk=pk)
