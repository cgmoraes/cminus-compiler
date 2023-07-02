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
python3 compiler/agen.py "$arquivo"
python3 compiler/bgen.py "$arquivo"