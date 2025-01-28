# MIPSHW1
# Mingwei Zhang
# 11/13/2023
# Program1

.data
	prompt1_int1: .asciiz "Enter a first integer in the range [100, 250]: " 
	prompt2_int2: .asciiz "Enter a second integer greater than -30: "
	invalid: .asciiz "The input is invalid \n"
	result: .asciiz "4*int1+ 7*(int2 -9) = "
	new_line: .asciiz "\n"

.text

main:
#Print string from prompt1
	li $v0, 4		#print string system call		
	la $a0, prompt1_int1
	syscall		
#Read int from prompt1
	li $v0, 5		# read integer system call
	syscall			
	move $t1, $v0		#integer stored into $t1 (int 1)
#Input check for prompt1
	blt $t1 100, invalid_message
	bgt $t1	250, invalid_message

#Print string from prompt2
	li $v0, 4
	la $a0, prompt2_int2
	syscall	
#Read int from prompt2
	li $v0, 5
	syscall
	move $t2, $v0		#integer stored into $t2 (int 2)
#Input check for prompt2
	blt $t2, -30, invalid_message

#Calcuate 4*int1+ 7*(int2 -9)  int1 and int2 from prompt1 and prompt2
	sub $t3, $t2, 9

	li $t4, 7
	mul $t4, $t4, $t3
	
	li $t5, 4
	mul $t5, $t5, $t1
	
	add $t6, $t4, $t5

# Print Result
	j print		

print:
	li $v0, 4		# print string system call 
	la $a0, result
	syscall
	
	li $v0, 1		# print integer system call 
	move $a0, $t6
	syscall
	
	li $v0, 4		# print string system call 
	la $a0, new_line
	syscall
	
	j main		# repeat by jump to "main" function

invalid_message: 
	li $v0, 4
	la $a0, invalid
	syscall
	j main		
