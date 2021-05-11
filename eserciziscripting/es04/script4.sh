#!/bin/bash
if [ "$#" -gt 1  ]
then
	echo "hai inserito troppi argomenti stronzo"
	exit 
elif [ "$#" -eq 0 ]
	then 
		echo "non ci sono argomenti"
		exit 
fi 

if [ -f "$1" ]
then 
	cat -n $1
fi 