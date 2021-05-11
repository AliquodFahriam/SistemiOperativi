#!/bin/bash
#cd $1; 
for file in  *
do
	if [ -n "$(grep -H "$1" $file)" ]
	then 
		echo "$file" 
		chmod 'g=-' $file  
		chmod 'o=-' $file 
	fi 
done 	 
	
