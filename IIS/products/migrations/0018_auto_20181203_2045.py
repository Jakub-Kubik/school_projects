# Generated by Django 2.1.3 on 2018-12-03 20:45

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0017_auto_20181203_2036'),
    ]

    operations = [
        migrations.RenameField(
            model_name='costumes',
            old_name='decription',
            new_name='description',
        ),
    ]
