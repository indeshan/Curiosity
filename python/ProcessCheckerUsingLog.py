#This script extact last line from log file and check log time with current time 
#if time difference is more than 5min then send mail using sendGrid.
##`sudo pip install sendgrid` #install sendgrid package before use
import time
from time import mktime
from datetime import datetime
import os
from sendgrid import SendGridAPIClient
from sendgrid.helpers.mail import Mail

with open('/PATH/To/LOG/FILE.log') as f:
	x=f.readlines()
last_line = ''.join(x[-1:])
last_line = last_line.split(',')
now = time.strftime('%Y-%m-%d %H:%M:%S')
datetimeFormat = '%Y-%m-%d %H:%M:%S'
t1 = datetime.strptime(last_line[0], datetimeFormat)
t2 = datetime.strptime(now, datetimeFormat)

difference_in_seconds = abs(mktime(t2.timetuple()) - mktime(t1.timetuple()))

if(difference_in_seconds > 300):
	message = Mail(
		from_email='sender@example.com',
		to_emails='receiver@example.com',
		subject='Process Down',
		html_content='<strong>Please do something</strong>')
	try:
		sg = SendGridAPIClient('SENDGRID_API_KEY')
		response = sg.send(message)
		print(now + " Process is down, mail sent!")
	except Exception as e:
		print(e.message)
else:
	print(now + " Process running fine.")
