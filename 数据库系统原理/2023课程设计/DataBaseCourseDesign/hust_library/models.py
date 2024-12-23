from django.core.validators import MinValueValidator, MaxValueValidator
from django.db import models
from django.contrib.auth.models import User
from django.conf import settings


class Ticket(models.Model):
    price = models.DecimalField(max_digits=6, decimal_places=2)
    time = models.DateTimeField()
    quantity = models.SmallIntegerField(default=1)
    description = models.CharField(max_length=150)
    address = models.CharField(max_length=150)
    state = models.IntegerField(default=0)
    reader = models.ForeignKey(
        User, on_delete=models.CASCADE, related_name="ticket_reader_id")

    def __str__(self):
        return self.description


class Book(models.Model):
    name = models.CharField(max_length=150)
    publish = models.CharField(max_length=150)
    time = models.IntegerField()
    price = models.DecimalField(max_digits=6, decimal_places=2)
    keyword = models.CharField(max_length=150)
    stock = models.SmallIntegerField(default=0)
    supplier = models.CharField(max_length=10, null=False)
    seriesNo = models.IntegerField()

    class Meta:
        unique_together = ("name", "publish", "time", "price", "keyword", "stock", "supplier", "seriesNo")

    def __str__(self):
        return self.name


class Write(models.Model):
    writer = models.CharField(max_length=150)
    book = models.ForeignKey(Book, on_delete=models.CASCADE)

    def __str__(self):
        return self.writer

    class Meta:
        unique_together = ("writer", "book")


class Store(models.Model):
    location = models.CharField(max_length=150)
    state = models.SmallIntegerField(default=1)
    book = models.ForeignKey(Book, on_delete=models.CASCADE)

    def __str__(self):
        return self.location


class Loan(models.Model):
    time = models.DateTimeField()
    state = models.SmallIntegerField(default=0)
    store = models.ForeignKey(Store, on_delete=models.CASCADE)
    reader = models.ForeignKey(
        User, on_delete=models.CASCADE, related_name="loan_reader_id")


class BookShortage(models.Model):
    name = models.CharField(max_length=150)
    publish = models.CharField(max_length=150)
    supplier = models.CharField(max_length=10)
    quantity = models.IntegerField(null=False, validators=[
        MinValueValidator(10),
        MaxValueValidator(9999)
    ])
    registrationDate = models.IntegerField()

    def __str__(self):
        return self.name


class Reader(models.Model):
    user = models.OneToOneField(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    address = models.CharField(max_length=300)
    balance = models.DecimalField(max_digits=10, decimal_places=2)
    credit_rating = models.IntegerField()

    def __str__(self):
        return self.user.username

class Supplier(models.Model):
    name = models.CharField(max_length=30)
    phoneNumber = models.CharField(max_length=11)
    supplyInfo = models.TextField()

    def __str__(self):
        return self.name
