"""library URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from django.contrib.auth import views as auth_views
from hust_library import views

urlpatterns = [
    path('', views.index_view, name='index'),
    path('admin/', admin.site.urls),
    path('login/', auth_views.LoginView.as_view(template_name='login.html'), name='login'),
    path('logout/', auth_views.logout_then_login, name='logout'),
    path('is_admin/', views.is_admin_view, name='is_admin'),
    path('self_inf/', views.self_inf_view, name='self_inf'),
    path('loans/', views.loans_view, name='loans'),
    path('loaned/', views.loaned_view, name='loaned'),
    path('loaned/renew/<int:pk>', views.renew_view, name='renew'),
    path('tickets/', views.tickets_view, name='tickets'),
    path('tickets/handle/<int:pk>/',
         views.ticket_handle_view, name='ticket_handle'),
    path('books/', views.books_view, name='books'),
    path('books/<int:pk>/', views.BookView.as_view(), name='book'),
    path('administrator/', views.administrator_view, name='administrator'),
    path('administrator/books_manage/',
         views.books_manage_view, name='books_manage'),
    path('administrator/books_manage/<int:pk>/',
         views.book_manage_view, name='book_manage'),
    path('administrator/books_manage/new/',
         views.new_book_view, name='new_book'),
    path('administrator/books_manage/edit/<int:pk>/',
         views.edit_book_view, name='edit_book'),
    path('administrator/books_manage/delete/<int:pk>/',
         views.delete_book_view, name='delete_book'),
    path('administrator/books_manage/write/<int:book_pk>/',
         views.write_view, name='write'),
    path('administrator/books_manage/<int:book_pk>/write/new/',
         views.new_write_view, name='new_write'),
    path('administrator/books_manage/write/edit/<int:pk>/',
         views.edit_write_view, name='edit_write'),
    path('administrator/books_manage/write/delete/<int:pk>/',
         views.delete_write_view, name='delete_write'),
    path('administrator/books_manage/store/<int:book_pk>/',
         views.store_view, name='store'),
    path('administrator/books_manage/<int:book_pk>/store/new/',
         views.new_store_view, name='new_store'),
    path('administrator/books_manage/store/edit/<int:pk>/',
         views.edit_store_view, name='edit_store'),
    path('administrator/books_manage/store/delete/<int:pk>/',
         views.delete_store_view, name='delete_store'),
    path('administrator/readers_manage/',
         views.readers_manage_view, name='readers_manage'),
    path('administrator/readers_manage/<int:pk>/',
         views.reader_manage_view, name='reader_manage'),
    path('administrator/readers_manage/new/',
         views.new_reader_view, name='new_reader'),
    path('administrator/readers_manage/edit/<int:pk>/',
         views.edit_reader_view, name='edit_reader'),
    path('administrator/readers_manage/delete/<int:pk>/',
         views.delete_reader_view, name='delete_reader'),
    path('administrator/readers_manage/set_password/<int:pk>/',
         views.set_password_view, name='set_password'),
    path('administrator/borrow_manage/',
         views.borrow_manage_view, name='borrow_manage'),
    path('administrator/return_manage/',
         views.return_manage_view, name='return_manage')
]
