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
number1: .word 47
message: .asciiz "FIN"
.text
lw $t0, number1($zero)
li $v0, 1
add $a0, $zero, $t-2
syscall
..............................................
..............................................
.data
number2: .word 60
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
..............................................
.data
number2: .word 10
number1: .word 2
message: .asciiz "FIN"
.text
lw $t0, number2($zero)
lw $t1, number1($zero)
div $t2, $t1, $t0
li $v0, 1
add $a0, $zero, $t2
syscall
..............................................
..............................................
.data
message: .asciiz "FIN"
.text
li $v0, 1
add $a0, $zero, $t-2
syscall
..............................................
..............................................
.data
number3: .word 60
number2: .word 47
number1: .word 69
message: .asciiz "FIN"
.text
addi $t0, $zero, 60
addi $t1, $zero, 47
blt $t0, $t1, operation
li $v0, 10
syscall
operation:
lw $t2, number1($zero)
li $v0, 1
li $v0, 10
syscall
..............................................
..............................................
.data
number3: .word 44
number2: .word 47
number1: .word 70
message: .asciiz "FIN"
.text
addi $t0, $zero, 44
addi $t1, $zero, 47
while:
blt $t0, $t1, exit
jal  operation
addi $t0, $t0, 1
j while
exit:
li $v0, 4
la $a0, message
syscall
li $v0, 10
syscall
operation:
lw $t2, number1($zero)
li $v0, 1
jr $ra
syscall
..............................................
