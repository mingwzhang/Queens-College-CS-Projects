.data
	prompt1: .asciiz "Input 1: "
	prompt2: .asciiz "Input 2: "


.text
	li $v0, 4
	la $a0, prompt1
	syscall
	
	li $v0, 5 #read int
	syscall
	move $s0, $v0
	
	li $v0, 4
	la $a0, prompt2
	syscall
	
	li $v0, 5 #read int
	syscall
	move $s1, $v0
	
	add $t0, $s0, $s1
	
	li $v0, 1  # print int
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
