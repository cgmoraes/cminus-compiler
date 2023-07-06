J 37
SW $r29 $r31 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $r29 $t1 2
ADDI $t0 $t2 1
SGET $t1 $t2 $t3
BEQ $t0 $t3 24
LW $r29 $t1 2
LW $r29 $t2 2
ADDI $t0 $t3 1
SUB $t2 $t3 $t4
SW $r30 $t1 0
ADDI $r30 $r30 1
SW $r30 $t4 0
ADDI $r30 $r30 1
SW $r30 $r29 0
ADDI $r30 $r29 0
ADDI $r30 $r30 1
SW $r29 $t4 2
JAL 1
ADDI $r29 $r30 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $r30 $t4 0
SUBI $r30 $r30 1
LW $r30 $t1 0
ADD $t0 $t28 $t2
MULT $t1 $t2 $t3
ADDI $t3 $t28 0
J 35
J 35
ADDI $t0 $t1 1
ADDI $t1 $t28 0
J 35
LW $r29 $r31 1
JR $r31
ADDI $r30 $r29 0
ADDI $r30 $r30 1
IN $t28
SW $r29 $t28 0
LW $r29 $t1 0
SW $r30 $t1 0
ADDI $r30 $r30 1
SW $r30 $r29 0
ADDI $r30 $r29 0
ADDI $r30 $r30 1
SW $r29 $t1 2
JAL 1
ADDI $r29 $r30 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $r30 $t1 0
ADD $t0 $t28 $t1
OUT $t1
HALT
