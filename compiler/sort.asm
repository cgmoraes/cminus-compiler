Unknown - AARR
.minloc
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 $r29 1
Unknown - ASSIGN
SW $t1 $r29 5
LW $t0 $r29 1
ADDI $t2 $zero 4
MULT $t3 $t0 $t2
Unknown a($t4)
Unknown - ASSIGN
SW $t5 $r29 4
LW $t6 $r29 1
ADDI $t7 $zero 1
ADD $t8 $t6 $t7
Unknown - ASSIGN
SW $t9 $r29 3
.L0
LW $t9 $r29 3
LW $t10 $r29 2
LT $t11 $t9 $t10
Unknown - WHILE
LW $t9 $r29 3
ADDI $t10 $zero 4
MULT $t11 $t9 $t10
Unknown a($t16)
LW $t10 $r29 4
LT $t11 $t9 $t10
IFF $t11 L2
LW $t1 $r29 3
ADDI $t9 $zero 4
MULT $t10 $t1 $t9
Unknown a($t22)
Unknown - ASSIGN
SW $t9 $r29 4
LW $t1 $r29 3
Unknown - ASSIGN
SW $t9 $r29 5
J L3
.L2
.L3
LW $t1 $r29 3
ADDI $t9 $zero 1
ADD $t10 $t1 $t9
Unknown - ASSIGN
SW $t1 $r29 3
J L0
.L1
LW $t0 $r29 5
Unknown - RET
.FIMFUN minloc
.sort
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 $r29 1
Unknown - ASSIGN
SW $t1 $r29 3
.L4
LW $t0 $r29 2
ADDI $t1 $zero 1
SUB $t9 $t0 $t1
LW $t0 $r29 3
LT $t1 $t0 $t9
Unknown - WHILE
ADDI $r30 $r30 1
LW $t0 $r29 0
Unknown - PARAM
LW $t0 $r29 3
Unknown - PARAM
LW $t0 $r29 2
Unknown - PARAM
Unknown - CALL
Unknown - ASSIGN
SW $t1 $r29 4
LW $t0 $r29 4
ADDI $t1 $zero 4
MULT $t2 $t0 $t1
Unknown a($t46)
Unknown - ASSIGN
SW $t1 $r29 5
LW $t0 $r29 3
ADDI $t1 $zero 4
MULT $t2 $t0 $t1
Unknown a($t51)
Unknown - ASSIGN
LW $t0 $r29 4
ADDI $t2 $zero 4
MULT $t3 $t0 $t2
Unknown a($t56)
LW $t0 $r29 5
Unknown - ASSIGN
LW $t0 $r29 3
ADDI $t2 $zero 4
MULT $t3 $t0 $t2
Unknown a($t61)
LW $t0 $r29 3
ADDI $t1 $zero 1
ADD $t2 $t0 $t1
Unknown - ASSIGN
SW $t0 $r29 3
J L4
.L5
.FIMFUN sort
.main
ADDI $r30 $r30 1
ADDI $t0 $zero 0
Unknown - ASSIGN
SW $t1 $r29 0
.L6
LW $t0 $r29 0
ADDI $t1 $zero 10
LT $t2 $t0 $t1
Unknown - WHILE
Unknown - INPUT
Unknown - ASSIGN
LW $t0 $r29 0
ADDI $t2 $zero 4
MULT $t3 $t0 $t2
Unknown vet($t75)
LW $t0 $r29 0
ADDI $t1 $zero 1
ADD $t2 $t0 $t1
Unknown - ASSIGN
SW $t0 $r29 0
J L6
.L7
Unknown - PARAM
ADDI $t0 $zero 0
Unknown - PARAM
ADDI $t0 $zero 10
Unknown - PARAM
Unknown - CALL
ADDI $t0 $zero 0
Unknown - ASSIGN
SW $t1 $r29 0
.L8
LW $t0 $r29 0
ADDI $t1 $zero 10
LT $t2 $t0 $t1
Unknown - WHILE
LW $t0 $r29 0
ADDI $t1 $zero 4
MULT $t2 $t0 $t1
Unknown vet($t91)
Unknown - OUTPUT
LW $t0 $r29 0
ADDI $t1 $zero 1
ADD $t2 $t0 $t1
Unknown - ASSIGN
SW $t0 $r29 0
J L8
.L9
.FIMFUN main
HALT
