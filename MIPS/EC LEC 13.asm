# Mingwei Zhang
# 11/13/2023
# EC LEC 13

.data
	prompt1_int1: .asciiz "Enter first integer: " 
	prompt2_int2: .asciiz "Enter second integer: "
	equation: .asciiz "(int1 + int2) * 8 - 200 = "

.text
#Print string from prompt1
	li $v0, 4		#print string system call		
	la $a0, prompt1_int1
	syscall		
#Read int from prompt1
	li $v0, 5		# read integer system call
	syscall			
	move $s0, $v0		#integer stored into (int 1)

#Print string from prompt2
	li $v0, 4
	la $a0, prompt2_int2
	syscall	
#Read int from prompt2
	li $v0, 5
	syscall
	move $s1, $v0		#integer stored into $s1 (int 2)
	
#Calcuate (int1 + int2) * 8 - 200 
	add $t0, $s0, $s1      #$t0 ← int1 + int2
	sll $t0, $t0, 3        #$t0 ← (int1 + int2) * 8
	addi $s2, $t0, -200    #$s2 ← (int1 + int2) * 8 - 200
	
#Print
	li $v0, 4		# print string system call 
	la $a0, equation
	syscall
	
	li $v0, 1		# print integer system call 
	move $a0, $s2
	syscall

#Exit
	li $v0, 10
	syscall
