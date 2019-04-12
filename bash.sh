#!/bin/sh
filename = "dictionary.txt"
while read -r line;
 do
 	name ="$line"
 	echo "$name"
 done < "$filename"
 