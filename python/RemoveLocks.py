# This script remove all .lock files which are older than 3 hours from specified directory.
import os.path, time, glob, datetime
allFiles = (glob.glob("/home/ubuntu/tmp/locks/*.lock"))
for x in allFiles:
	if time.time() - os.path.getmtime(x) > (3 * 60 * 60): #delete all lock files created before 3 hrs.
		os.remove(x)
		print "removed "+x+" at "+str(datetime.datetime.now())+"\n"
