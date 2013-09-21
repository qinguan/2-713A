#!/usr/bin/env python

str="12 34 56"
strlist = str.split(" ")
length = len(strlist)
for i in range(length-1,-1,-1):
	print strlist[i]
for  item in strlist:
	print item
