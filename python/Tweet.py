from twython import Twython
import requests

# Twitter API credentials
API_KEY = ''
API_SECRET = ''
OAUTH_TOKEN = ''
OAUTH_TOKEN_SECRET = ''

# Connect to twitter
twitter = Twython(API_KEY, API_SECRET, OAUTH_TOKEN, OAUTH_TOKEN_SECRET)

# Format tweet
tweet = '%s' %("write what you want to tweet here")

# Post tweet
twitter.update_status(status=tweet)
