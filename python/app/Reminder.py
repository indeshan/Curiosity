import time, os, urllib, requests
birthdayFile = 'birthday.txt'
anniversaryFile = 'anniversary.txt'

def checkTodaysBirthdays():
    fileName = open(birthdayFile, 'r')
    today = time.strftime('%m%d')
    birthday = ''
    for line in fileName:
        if today in line:
            line = line.split(' ')
            birthday += line[1] + ' ' + line[2].rstrip("\n\r") + ', '
    return birthday

def checkTodaysAnniversarys():
    fileName = open(anniversaryFile, 'r')
    today = time.strftime('%m%d')
    anniversary = ''
    for line in fileName:
        if today in line:
            line = line.split(' ')
            anniversary += line[1] + ' and ' + line[2] + ' '+ line[3].rstrip("\n\r")  +', '
    return anniversary

if __name__ == '__main__':
    os.environ['TZ'] = 'Asia/Calcutta'
    time.tzset()
    c = ''
    a = checkTodaysBirthdays()
    if a :
        c += "Today's B'days: " + a + '\n'
    b = checkTodaysAnniversarys()
    if b :
        c += "Today's Anniversaries: " + b
    if c :
        url = "https://www.fast2sms.com/dev/bulk"
        payload = "sender_id=FSTSMS&message=" + urllib.quote(c) + "&language=english&route=p&numbers=PHONE_NUMBER"
        headers = {'authorization': "API_KEY",'Content-Type': "application/x-www-form-urlencoded",'Cache-Control': "no-cache",}
        response = requests.request("POST", url, data=payload, headers=headers)
        print(response.text)
