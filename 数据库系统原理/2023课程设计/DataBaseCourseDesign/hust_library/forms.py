from django import forms
from django.utils.translation import gettext_lazy as _
from . import models


class BorrowManageForm(forms.Form):
    store_id = forms.IntegerField(label='藏书号')
    username = forms.CharField(label='用户名', max_length=150)


class ReturnManageForm(forms.Form):
    store_id = forms.IntegerField(label='藏书号')
    is_broken = forms.BooleanField(label='书籍损坏', required=False)


class BookForm(forms.ModelForm):
    class Meta:
        model = models.Book
        fields = ['name', 'publish', 'time', 'price']
        labels = {
            'name': _('书名'),
            'publish': _('出版社'),
            'time': _('出版时间'),
            'price': _('价格')
        }


class ReaderForm(forms.Form):
    username = forms.CharField(label='用户名', max_length=150)
    last_name = forms.CharField(label='姓', max_length=150)
    first_name = forms.CharField(label='名', max_length=30)
    email = forms.EmailField(label='邮箱')
    # address = forms.CharField(label='地址', max_length=300)
    # balance = forms.DecimalField(label='账户余额', max_digits=10, decimal_places=2)
    # creditLevel = forms.IntegerField(label='信用等级')
