#!/bin/bash

if [ $# -eq 0 ]
then
	echo "specificare un parametro di input" 
elif [ $# -gt 1 ] 
then 
	echo "troppi parametri di input"
else
	ls -la | awk -v arg = "$1" '$6 - "^" arg {print $9}'
fi
 
