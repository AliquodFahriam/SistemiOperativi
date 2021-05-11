#!/bin/bash
for  arg in *.txt 
do
	grep -q "cane e gatto" $arg && echo "$arg"| awk -F . '{print$1}'
done
