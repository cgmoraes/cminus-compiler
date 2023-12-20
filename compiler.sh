#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Por favor, forneça pelo menos um arquivo."
  exit 1
fi

SO=1
linhas=0
extensoes=("out" "ic" "asm" "bin")

extensoes_find=""
for extensao in "${extensoes[@]}"; do
  extensoes_find+=" -name '*.$extensao' -o"
done
extensoes_find=${extensoes_find::-3} 

eval "find . -type f \( $extensoes_find \) -delete"

for arquivo in "$@"; do
  if [ "$linhas" = 0 ]; then
    linhas="$arquivo"
  elif [ -e "$arquivo.cm" ]; then
    cd compiler
    make
    cd ..
    ./compiler/cmc "$arquivo" -o "$arquivo"

    if ! ls *.ic 1> /dev/null 2>&1; then
      echo "Erro de compilação."
      exit 1
    fi

    python3 compiler/agen.py "$SO" "$arquivo"
    python3 compiler/bgen.py "$SO" "$arquivo" "$linhas"
    python3 compiler/concat.py "$arquivo"
    rm "$arquivo.bin"
    rm "$arquivo.ic"

    if [ "$SO" = 1 ]; then     
      SO=0
    fi
  else
    echo "O arquivo '$arquivo' não existe."
  fi
done

rm compiler/symtab.csv
extensoes=("out" "asm")

extensoes_find=""
for extensao in "${extensoes[@]}"; do
  extensoes_find+=" -name '*.$extensao' -o"
done
extensoes_find=${extensoes_find::-3} 

eval "find . -type f \( $extensoes_find \) -delete"

# cd compiler
# make
# cd ..
# ./compiler/cmc "$arquivo" -o "$arquivo"

# if ! ls *.ic 1> /dev/null 2>&1; then
#   echo "Erro de compilação."
#   exit 1
# fi

# python3 compiler/agen.py "$tipo" "$arquivo"

# rm compiler/symtab.csv

# python3 compiler/bgen.py "$tipo" "$arquivo"