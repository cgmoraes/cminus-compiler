J 43
SW $r31 $r29 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t1 $r29 3
ADDI $t2 $r0 0
AND $t3 $t1 $t2
BEQ $r0 $t3 12
LW $t1 $r29 2
ADDI $r28 $r28 0
J 41
LW $t1 $r29 3
LW $t2 $r29 2
LW $t3 $r29 3
DIV $t4 $t2 $t3
LW $t2 $r29 3
MULT $t3 $t4 $t2
LW $t2 $r29 2
SUB $t4 $t2 $t3
SW $t1 $r30 0
ADDI $r30 $r30 1
SW $t2 $r30 0
ADDI $r30 $r30 1
SW $t4 $r30 0
ADDI $r30 $r30 1
SW $r29 $r30 0
ADDI $r29 $r30 0
ADDI $r30 $r30 1
SW $t4 $r29 3
SW $t1 $r29 2
JAL 1
ADDI $r30 $r29 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $t4 $r30 0
SUBI $r30 $r30 1
LW $t2 $r30 0
SUBI $r30 $r30 1
LW $t1 $r30 0
ADDI $r28 $r28 0
LW $r31 $r29 1
JR $r31
ADDI $r30 $r30 1
ADDI $r30 $r30 1
IN $t1
SW $t1 $r29 0
IN $t1
SW $t1 $r29 1
LW $t1 $r29 0
LW $t2 $r29 1
SW $t1 $r30 0
ADDI $r30 $r30 1
SW $t2 $r30 0
ADDI $r30 $r30 1
SW $t3 $r30 0
ADDI $r30 $r30 1
SW $r29 $r30 0
ADDI $r29 $r30 0
ADDI $r30 $r30 1
SW $t2 $r29 3
SW $t1 $r29 2
JAL 1
ADDI $r30 $r29 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $t3 $r30 0
SUBI $r30 $r30 1
LW $t2 $r30 0
SUBI $r30 $r30 1
LW $t1 $r30 0
OUT $t3
HALT
