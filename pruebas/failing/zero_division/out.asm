..............................................
.data
number2: .word 4
number1: .word 40
message: .asciiz "FIN"
.text
lw $t0, number2($zero)
lw $t1, number1($zero)
add $t2, $t1, $t0
li $v0, 1
add $a0, $zero, $t2
syscall
..............................................
..............................................
.data
number1: .word 40
message: .asciiz "FIN"
.text
lw $t0, number1($zero)
li $v0, 1
add $a0, $zero, $t-2
syscall
..............................................
..............................................
.data
number2: .word 5
number1: .word 1
message: .asciiz "FIN"
.text
lw $t0, number2($zero)
lw $t1, number1($zero)
mul $t2, $t1, $t0
li $v0, 1
add $a0, $zero, $t2
syscall
..............................................
