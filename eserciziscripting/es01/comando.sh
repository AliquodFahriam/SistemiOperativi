#!/bin/bash
max1="a"
for arg in *
do
if [ -f $arg ]
then
	echo "$(grep -E 'a[1-9]{1,}' $arg)" 
	if [ "$(grep -E 'a[1-9]{1,}' $arg)" = "$(grep -E 'a[1-9]{1,}' $arg)" ]
	then 
		awk -F - '{print$2}' $arg 
		#echo "$arg"
		#mv $arg dirA
	fi
fi
done 
