ADDI $r30 $r30 10
J 117
SW $r29 $r31 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $r29 $t17 3
SW $r29 $t17 7
LW $r29 $t17 3
LW $r29 $t18 2
ADD $t18 $t17 $t18
LW $t18 $t18 0
SW $r29 $t18 6
LW $r29 $t17 3
ADDI $t16 $t18 1
ADD $t17 $t18 $t19
SW $r29 $t19 5
LW $r29 $t17 5
LW $r29 $t18 4
SLT $t17 $t18 $t19
BEQ $t16 $t19 20
LW $r29 $t17 5
LW $r29 $t18 2
ADD $t18 $t17 $t18
LW $t18 $t18 0
LW $r29 $t17 6
SLT $t18 $t17 $t19
BEQ $t16 $t19 8
LW $r29 $t17 5
LW $r29 $t18 2
ADD $t18 $t17 $t18
LW $t18 $t18 0
SW $r29 $t18 6
LW $r29 $t17 5
SW $r29 $t17 7
J 40
LW $r29 $t17 5
ADDI $t16 $t18 1
ADD $t17 $t18 $t19
SW $r29 $t19 5
J 21
LW $r29 $t17 7
ADDI $t17 $t28 0
J 48
LW $r29 $r31 1
JR $r31
SW $r29 $r31 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
ADDI $r30 $r30 1
LW $r29 $t17 3
SW $r29 $t17 5
LW $r29 $t17 4
ADDI $t16 $t18 1
SUB $t17 $t18 $t19
LW $r29 $t17 5
SLT $t17 $t19 $t18
BEQ $t16 $t18 50
ADDI $r30 $r30 1
LW $r29 $t17 2
LW $r29 $t18 5
LW $r29 $t19 4
SW $r30 $t17 0
ADDI $r30 $r30 1
SW $r30 $t18 0
ADDI $r30 $r30 1
SW $r30 $t19 0
ADDI $r30 $r30 1
SW $r30 $r29 0
ADDI $r30 $r29 0
ADDI $r30 $r30 1
SW $r29 $t19 4
SW $r29 $t18 3
SW $r29 $t17 2
JAL 2
ADDI $r29 $r30 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $r30 $t19 0
SUBI $r30 $r30 1
LW $r30 $t18 0
SUBI $r30 $r30 1
LW $r30 $t17 0
ADD $t16 $t28 $t17
SW $r29 $t17 6
LW $r29 $t17 6
LW $r29 $t18 2
ADD $t18 $t17 $t18
LW $t18 $t18 0
SW $r29 $t18 7
LW $r29 $t17 5
LW $r29 $t18 2
ADD $t18 $t17 $t18
LW $t18 $t18 0
LW $r29 $t17 6
LW $r29 $t19 2
ADD $t19 $t17 $t17
SW $t17 $t18 0
LW $r29 $t17 7
LW $r29 $t18 5
LW $r29 $t19 2
ADD $t19 $t18 $t18
SW $t18 $t17 0
LW $r29 $t17 5
ADDI $t16 $t18 1
ADD $t17 $t18 $t19
SW $r29 $t19 5
J 59
LW $r29 $r31 1
JR $r31
ADDI $r30 $r29 0
ADDI $r30 $r30 1
ADDI $t16 $t17 0
SW $r29 $t17 0
LW $r29 $t17 0
ADDI $t16 $t18 10
SLT $t17 $t18 $t19
BEQ $t16 $t19 9
IN $t28
LW $r29 $t17 0
ADDI $t17 $t17 0
SW $t17 $t28 0
LW $r29 $t17 0
ADDI $t16 $t18 1
ADD $t17 $t18 $t19
SW $r29 $t19 0
J 121
LW $t16 $t17 0
ADDI $t16 $t17 0
ADDI $t16 $t18 0
ADDI $t16 $t19 10
SW $r30 $t17 0
ADDI $r30 $r30 1
SW $r30 $t18 0
ADDI $r30 $r30 1
SW $r30 $t19 0
ADDI $r30 $r30 1
SW $r30 $r29 0
ADDI $r30 $r29 0
ADDI $r30 $r30 1
SW $r29 $t19 4
SW $r29 $t18 3
SW $r29 $t17 2
JAL 50
ADDI $r29 $r30 0
LW $r29 $r29 0
SUBI $r30 $r30 1
LW $r30 $t19 0
SUBI $r30 $r30 1
LW $r30 $t18 0
SUBI $r30 $r30 1
LW $r30 $t17 0
ADD $t16 $t28 $t17
ADDI $t16 $t17 0
SW $r29 $t17 0
LW $r29 $t17 0
ADDI $t16 $t18 10
SLT $t17 $t18 $t19
BEQ $t16 $t19 9
LW $r29 $t17 0
ADDI $t17 $t17 0
LW $t17 $t18 0
OUT $t18
LW $r29 $t17 0
ADDI $t16 $t18 1
ADD $t17 $t18 $t19
SW $r29 $t19 0
J 162
HALT
