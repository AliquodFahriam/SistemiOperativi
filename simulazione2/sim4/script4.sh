#!/bin/bash 
if [ "$#" -eq 2 ] #cambiare in 3 quando si aggiunge cd 
then 

	cd $1 

	for arg in [aA]*
	do 
		chown $2:$3 $arg #cambaire in 2/3 dopo l'inserimento di CD 
	done
else 
	echo "hai inserito troppi o troppo pochi argomenti"
fi 