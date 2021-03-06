# Generated by Django 2.1.3 on 2018-12-02 15:50

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='accessory',
            name='product',
            field=models.OneToOneField(on_delete=django.db.models.deletion.DO_NOTHING, primary_key=True, serialize=False, to='products.Products'),
        ),
        migrations.AlterField(
            model_name='costumes',
            name='product',
            field=models.OneToOneField(on_delete=django.db.models.deletion.DO_NOTHING, primary_key=True, serialize=False, to='products.Products'),
        ),
        migrations.AlterField(
            model_name='products',
            name='manager',
            field=models.OneToOneField(db_column='manager', on_delete=django.db.models.deletion.DO_NOTHING, to=settings.AUTH_USER_MODEL),
        ),
    ]
