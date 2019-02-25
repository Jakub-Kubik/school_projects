# Generated by Django 2.1.3 on 2018-12-03 19:50

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0014_auto_20181203_1949'),
    ]

    operations = [
        migrations.AlterField(
            model_name='products',
            name='manager',
            field=models.OneToOneField(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL),
        ),
    ]