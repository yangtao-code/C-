#! /bin/bash

#a='10'
#b=30
#c=`ls`
#d=`pwd`
#echo a=$a
#echo b=$b
#echo c=${c}


echo "please input a filename"
read filename

if  [ -d $filename ] ; then
	ls $filename >> test.txt
	
else
	ls -l  $filename >> test.txt
fi
