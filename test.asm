J 42
SW $r29 $r31 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $t0 $t1 0
SW $r29 $t1 3
ADDI $t0 $t1 1
SW $r29 $t1 4
ADDI $t0 $t1 2
SW $r29 $t1 6
LW $r29 $t1 2
ADDI $t0 $t2 0
SET $t1 $t2 $t3
BEQ $t0 $t3 3
LW $r29 $t1 3
ADDI $t1 $t28 0
J 21
LW $r29 $t1 6
LW $r29 $t2 2
SLET $t1 $t2 $t3
BEQ $t0 $t3 13
LW $r29 $t1 3
LW $r29 $t2 4
ADD $t1 $t2 $t3
SW $r29 $t3 5
LW $r29 $t1 4
SW $r29 $t1 3
LW $r29 $t1 5
SW $r29 $t1 4
LW $r29 $t1 6
ADDI $t0 $t2 1
ADD $t1 $t2 $t3
SW $r29 $t3 6
J 21
LW $r29 $t1 4
ADDI $t1 $t28 0
LW $r29 $r31 1
JR $r31
ADDI $r30 $r30 1
ADDI $t0 $t1 9
SW $r29 $t1 0
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
OUT $t28
HALT
