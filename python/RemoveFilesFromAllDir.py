# This Python file uses the following encoding: utf-8
# This script remove all file from given directory and sub-directories. 
import os,time,sys
project_path = "/home/ubuntu/tmp/abc"

for dname, dirs, files in os.walk(project_path):
	for fname in files:
		x = os.path.join(dname, fname)
		os.remove(x)
		print x + " Removed"
