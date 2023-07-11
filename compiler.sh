#!/bin/bash

if [ -z "$1" ]; then
  echo "Por favor, forneça o nome do arquivo como argumento."
  exit 1
fi

arquivo="$1"
extensoes=("out" "ic" "asm" "bin")

extensoes_find=""
for extensao in "${extensoes[@]}"; do
  extensoes_find+=" -name '*.$extensao' -o"
done
extensoes_find=${extensoes_find::-3} 

eval "find . -type f \( $extensoes_find \) -delete"

cd compiler
make
cd ..
./compiler/cmc "$arquivo" -o "$arquivo"

if ! ls *.ic 1> /dev/null 2>&1; then
  echo "Erro de compilação."
  exit 1
fi

python3 compiler/agen.py "$arquivo"

rm compiler/symtab.csv

python3 compiler/bgen.py "$arquivo"