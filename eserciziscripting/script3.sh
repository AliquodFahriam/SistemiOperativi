#!/bin/bash
cd $1
#egrep "[a-z]{2,}\.[a-z]{2,}\@[a-z]{2,}\.[a-z]" [a-z]*[1-9].txt
grep -E '[a-z]{2,}\.[a-z]{2,}\@[a-z]{2,}\.[a-z]' [a-z]*[1-9].txt| awk -F : '{print$2}'
