.main
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 $r29 1
ADDI $t1 $zero 0
EQ $t2 $t0 $t1
IFF $t2 L0
LW $t0 $r29 0
Unknown - RET
J L1
.L0
LW $t0 $r29 1
Unknown - PARAM
LW $t0 $r29 0
LW $t2 $r29 1
DIV $t3 $t0 $t2
LW $t0 $r29 1
MULT $t2 $t3 $t0
LW $t0 $r29 0
SUB $t3 $t0 $t2
Unknown - PARAM
Unknown - CALL
Unknown - RET
.L1
.FIMFUN main
HALT
