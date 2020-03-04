#sudo pip install sendgrid #install sendgrid package before use
import os
from sendgrid import SendGridAPIClient
from sendgrid.helpers.mail import Mail

message = Mail(
	from_email='abc@example.com',
	to_emails='xyz@example.com',
	subject='Test',
	html_content='<strong>Easy to do anywhere, even with Python</strong>')
try:
	sg = SendGridAPIClient('YOUR_API_KEY')
	response = sg.send(message)
	print(response.status_code)
	print(response.body)
	print(response.headers)
except Exception as e:
	print(e.message)
