import os, json
project_path = "/PATH/TO/PROJECT/DIRECTORY/"
extensions = ('.html', '.js') # Specify extention of file which contains Bootsrap code.
exclude_directories = set(['EXCLUDE_DIRECTORY_FOLDERNAME_1','EXCLUDE_DIRECTORY_FOLDERNAME_'])

with open('new_icon_mapping.json') as data_file:
	mappings = json.loads(data_file.read())

for dname, dirs, files in os.walk(project_path):
	dirs[:] = [d for d in dirs if d not in exclude_directories]
	for fname in files:
		if(fname.lower().endswith(extensions)):
			fpath = os.path.join(dname, fname)
			print fpath
			with open(fpath) as f:
				s = f.read()
				for oldicon in mappings:
					print(oldicon+' -> '+mappings[oldicon])
					s = s.replace(oldicon, mappings[oldicon])
				print s
			with open(fpath, "w") as f:
				f.write(s)