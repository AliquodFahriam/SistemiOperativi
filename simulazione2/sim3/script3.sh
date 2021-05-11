#!/bin/bash

#costruire uno script in grado di terminare un processo all'interno del sistema
#ricevere in input il nome del programma da terminare 
#controllare se è in esecuzione 
#controllare il numero di parametri richiesti

if [ "$#" -eq 1 ] #controllo parametri 
then

	pid=$(ps -e | grep $1 | awk '{print$1}')
	
	if [ -z "$pid" ] #controllo che il programma sia in esecuzione 
	then
		
		echo "il processo non è attualmente in esecuzione"
		exit 
		
	fi 

	kill $pid && echo "il processo $1 è stato arrestato" #arresto del processo 


else 
	echo "Inserire il nome del programma"
fi 