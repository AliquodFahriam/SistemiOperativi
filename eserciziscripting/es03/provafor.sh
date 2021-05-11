#!/bin/bash
#creare un ciclo for
for arg in "$@" # scrivere $@ significa considerare l'array di tutti gli elementi passati alla shell
do #inizio del for
	echo "$arg"
done #fine del for
