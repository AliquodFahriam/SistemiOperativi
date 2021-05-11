#!/bin/bash
#Soluzione nostra
mv $(ls | grep -E 'a[0-9]{1,}$') dirA
mv $(ls | grep -E 'b[0-9]{1,}$') dirB

#Soluzione usando AWK 
mv $(ls | awk  '/a[0-9]+$/ {print$1}') dirA  
mv $(ls | awk  '/b[0-9]+$/ {print$1}') dirB


#comandi del professore SBAGLIATO
ls -l | awk '/-a[0-9]+$/ {printf("%s \n",$9)}'
ls -l | awk '/-b[0-9]+$/ {printf("%s \n",$9)}'

mv $(ls -l | awk '/^[-l].a[0-9]+$/ {printf("%s ",$9)}') dirA
mv $(ls -l | awk '/^[-l].b[0-9]+$/ {printf("%s ",$9)}') dirB