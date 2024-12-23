from django.contrib import admin
from .models import Book, Store, Loan, Write, Ticket, BookShortage, Reader, Supplier

from hust_library.models import Supplier

# Register your models here.

admin.site.register(Book)
admin.site.register(Store)
admin.site.register(Loan)
admin.site.register(Write)
admin.site.register(Ticket)
admin.site.register(BookShortage)
admin.site.register(Reader)
admin.site.register(Supplier)

