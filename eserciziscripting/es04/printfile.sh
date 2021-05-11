#!/bin/bash
#controllo argomenti 
if [ "$#" -gt 1 ]
then 
	echo "hai inserito troppi argomenti"
	exit
fi

#controllo esistenza file
if [ -f $1 ] 
then 
	cat -n $1
else
	echo "file inesistente"
fi 

