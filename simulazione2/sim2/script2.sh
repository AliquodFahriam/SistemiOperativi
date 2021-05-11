#!/bin/bash

#Costruire uno script che riceva in input due estensioni e che cambi tutti 
#i file all'interno della cartella con la prima estensione e inserisca la seconda.
if [ "$#" -ne 3 ]
then 
	echo "hai inserito troppi o troppo pochi argomenti"
	exit
fi

cd $1


for arg in *."$2"
do
	prova=$(echo "$arg" | awk -F . '{print$1}')
	mv $arg $prova\.$3
done 



