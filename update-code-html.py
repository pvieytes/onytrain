#!/usr/bin/python

import os

def walk_dir(target_dir, file_list):
	for dirname, dirnames, filenames in os.walk(target_dir):
	    # print path to all subdirectories first.
	    for subdirname in dirnames:
	        file_list = walk_dir(subdirname, file_list)

	    # print path to all filenames.
	    for filename in filenames:
	        file_list.append(os.path.join(dirname, filename))
	return file_list

src_files =  walk_dir('src', [])

html_file = '_includes/src-files.html'
os.system('rm %s' % html_file)
f = open(html_file, 'w')
lines = []
for src_file in src_files:
	lines.append("<li><a href='https://github.com/pvieytes/onytrain/blob/gh-pages/%s'>%s</a></li>" % (src_file, src_file))
f.write("".join(lines))
f.close()