# This Python file uses the following encoding: utf-8
# This script remove all newline,tab and spaces from file name in given directory and sub-directories. 
import os,time,sys,re
project_path = "/home/ubuntu/Downloads/temp/"

for dname, dirs, files in os.walk(project_path):
	for fname in files:
		x = os.path.join(dname, fname)
		fname = fname.replace('\n', '').replace('\r', '').replace(' ', '')
		y = os.path.join(dname, fname)
		os.rename(x,y)
