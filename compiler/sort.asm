Unknown - AARR
.minloc
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 1
Unknown - ASSIGN
Unknown - STORE
LW $t0 1
Unknown - ADDI
MULT $t3 $t0 $t2
LW $t0 3
Unknown - ASSIGN
Unknown - STORE
LW $t0 1
Unknown - ADDI
ADD $t8 $t6 $t7
Unknown - ASSIGN
Unknown - STORE
.L0
LW $t0 3
LW $t0 2
LT $t11 $t9 $t10
Unknown - WHILE
LW $t0 3
Unknown - ADDI
MULT $t11 $t9 $t10
LW $t0 3
LW $t0 4
LT $t11 $t9 $t10
IFF $t11 L2
LW $t0 3
Unknown - ADDI
MULT $t10 $t1 $t9
LW $t0 3
Unknown - ASSIGN
Unknown - STORE
LW $t0 3
Unknown - ASSIGN
Unknown - STORE
J L3
.L2
.L3
LW $t0 3
Unknown - ADDI
ADD $t10 $t1 $t9
Unknown - ASSIGN
Unknown - STORE
J L0
.L1
LW $t0 5
Unknown - RET
.FIMFUN minloc
.sort
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $t0 1
Unknown - ASSIGN
Unknown - STORE
.L4
LW $t0 2
Unknown - ADDI
SUB $t9 $t0 $t1
LW $t0 3
LT $t1 $t0 $t9
Unknown - WHILE
ADDI $r30 $r30 1
LW $t0 0
Unknown - PARAM
LW $t0 3
Unknown - PARAM
LW $t0 2
Unknown - PARAM
Unknown - CALL
Unknown - ASSIGN
Unknown - STORE
LW $t0 4
Unknown - ADDI
MULT $t2 $t0 $t1
LW $t0 3
Unknown - ASSIGN
Unknown - STORE
LW $t0 3
Unknown - ADDI
MULT $t2 $t0 $t1
LW $t0 3
Unknown - ASSIGN
LW $t0 4
Unknown - ADDI
MULT $t3 $t0 $t2
Unknown - STORE
LW $t0 5
Unknown - ASSIGN
LW $t0 3
Unknown - ADDI
MULT $t3 $t0 $t2
Unknown - STORE
LW $t0 3
Unknown - ADDI
ADD $t2 $t0 $t1
Unknown - ASSIGN
Unknown - STORE
J L4
.L5
.FIMFUN sort
.main
ADDI $r30 $r30 1
Unknown - ADDI
Unknown - ASSIGN
Unknown - STORE
.L6
LW $t0 0
Unknown - ADDI
LT $t2 $t0 $t1
Unknown - WHILE
Unknown - INPUT
Unknown - ASSIGN
LW $t0 0
Unknown - ADDI
MULT $t3 $t0 $t2
Unknown - STORE
LW $t0 0
Unknown - ADDI
ADD $t2 $t0 $t1
Unknown - ASSIGN
Unknown - STORE
J L6
.L7
LW $t0 0
Unknown - PARAM
Unknown - ADDI
Unknown - PARAM
Unknown - ADDI
Unknown - PARAM
Unknown - CALL
Unknown - ADDI
Unknown - ASSIGN
Unknown - STORE
.L8
LW $t0 0
Unknown - ADDI
LT $t2 $t0 $t1
Unknown - WHILE
LW $t0 0
Unknown - ADDI
MULT $t2 $t0 $t1
LW $t0 3
Unknown - OUTPUT
LW $t0 0
Unknown - ADDI
ADD $t2 $t0 $t1
Unknown - ASSIGN
Unknown - STORE
J L8
.L9
.FIMFUN main
HALT
