#!/bin/sh

case $1 in
  -a | -A | --alpha )
    echo "alpha" ;;
  -b )
    echo "bravo" ;;
  -c )
    echo "charlie" ;;
  * )
    echo "opzione sconosciuta" ;;
esac
