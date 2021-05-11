#!/bin/bash

#Realizzare uno script che analizzi tutti i file con estensione .c presenti nella directory corrente
#contando in ciascuno di essi il numero di cicli for 
#Produrre in output un file report.txt contenente il numero di for trovati e il nome del file

for arg in *.c 
do 			#-c 	-H
	grep --count --with-filename "for" $arg >> report.txt 
done