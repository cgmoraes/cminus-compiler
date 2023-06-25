J main
.gcd
SW $r31 $r29 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 $r29 3
ADDI $t1 $zero 0
EQ $t2 $t0 $t1
IFF $t2 L0
LW $t0 $r29 2
ADDI $r28 $t0 0
J L1
.L0
LW $t0 $r29 3
LW $t1 $r29 2
LW $t2 $r29 3
DIV $t3 $t1 $t2
LW $t1 $r29 3
MULT $t2 $t3 $t1
LW $t1 $r29 2
SUB $t3 $t1 $t2
SW $t0 $r30 0
ADDI $r30 $r30 1
SW $t1 $r30 0
ADDI $r30 $r30 1
SW $t3 $r30 0
ADDI $r30 $r30 1
SW $r29 $r30 0
ADDI $r29 $r30 0
ADDI $r30 $r30 1
JAL gcd
SUBI $r30 $r30 1
LW $t3 $r30 0
SUBI $r30 $r30 1
LW $t1 $r30 0
SUBI $r30 $r30 1
LW $t0 $r30 0
ADDI $r28 $t1 0
.L1
.END gcd
LW $r31 $r29 1
JR $r31
.main
ADDI $r30 $r30 1
ADDI $r30 $r30 1
IN $t0
SW $t0 $r29 1
IN $t0
SW $t0 $r29 2
LW $t0 $r29 1
LW $t1 $r29 2
SW $t0 $r30 0
ADDI $r30 $r30 1
SW $t1 $r30 0
ADDI $r30 $r30 1
SW $t2 $r30 0
ADDI $r30 $r30 1
SW $r29 $r30 0
ADDI $r29 $r30 0
ADDI $r30 $r30 1
JAL gcd
SUBI $r30 $r30 1
LW $t2 $r30 0
SUBI $r30 $r30 1
LW $t1 $r30 0
SUBI $r30 $r30 1
LW $t0 $r30 0
OUT $t2
.END main
LW $r31 $r29 1
JR $r31
HALT
