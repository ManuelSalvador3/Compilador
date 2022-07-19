.data
number3: .word 69
number2: .word 40
number1: .word 70
message: .asciiz "FIN"
.text
addi $t0, $zero, 69
addi $t1, $zero, 40
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

