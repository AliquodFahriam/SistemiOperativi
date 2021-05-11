#!/bin/sh
if [ "$#" -eq 0 ]
then
  echo "Specificare un parametro in input"
elif [ "$#" -gt 1 ]
then
  echo "Troppi parametri"
else
  ls -la | awk -v arg="$1" '$6 ~ "^" arg && $1 ~ /^-/{print $9}'
fi
echo "~comando eseguito~"
