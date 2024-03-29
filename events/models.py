from django.db import models
from django.utils import timezone
from django.contrib.auth.models import AbstractUser
from django.core.validators import MinValueValidator
from datetime import timedelta


class Event(models.Model):
    title = models.CharField(max_length=80)
    description = models.TextField()
    city = models.CharField(max_length=30)
    location = models.CharField(max_length=100)
    date = models.DateField(null=False, default= timezone.now, validators=[MinValueValidator(timezone.now().date())])
    promoter = models.ForeignKey('MyUser', on_delete=models.CASCADE, related_name='events')
    attendees = models.ManyToManyField('MyUser', related_name='events_attending')
    following = models.ManyToManyField('MyUser', related_name='events_following')
    poster = models.URLField(blank = True)
    duration = models.DurationField(default=timedelta(hours=1))
    event_type = models.CharField(max_length=255, default='General')

    def _str_(self):
        return self.title

    def get_image_urls(self):
        return self.image_urls.split(',')

    def add_image_url(self, url):
        if self.image_urls:
            self.image_urls += ',{}'.format(url)
        else:
            self.image_urls = url
        self.save()    

class MyUser(AbstractUser):
    date_of_birth = models.DateField(blank=True, null=True)
    nationality = models.CharField(max_length=56)
    address = models.CharField(max_length=300)
    is_promoter = models.BooleanField(default=False)
    bio = models.CharField(max_length=500, default="")
    picture = models.URLField(blank = True)
    class Meta(AbstractUser.Meta):
        swappable = 'AUTH_USER_MODEL'

