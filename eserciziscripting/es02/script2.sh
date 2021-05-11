#!/bin/bash
#prova=`ls|cat` #prova=$(ls|cat)
for parola in *.txt
do
	grep -q "cane e gatto" $parola && echo "$parola" | awk -F . '{print$1}'
done 

