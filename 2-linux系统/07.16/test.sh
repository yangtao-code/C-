#! /bin/bash

i=1;
while [ $i -lt 101 ]
do
	a=`expr $i % 3`
	if [ $a -eq 0 ];then
		echo $i
	fi
	i=`expr $i + 1`
done
