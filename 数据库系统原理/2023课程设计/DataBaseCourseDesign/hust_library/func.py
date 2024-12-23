from django.utils import timezone
import datetime


def get_loaned(loans):
    store_set = set()
    loaned = []
    today = timezone.now().date()
    for loan in loans:
        if loan.state != 1 and loan.store.id not in store_set:
            date_ret = loan.time.date()+datetime.timedelta(days=30)
            loaned.append(
                {"date": date_ret, "remain": (date_ret-today).days, "loan": loan})
        store_set.add(loan.store.id)
    return loaned
