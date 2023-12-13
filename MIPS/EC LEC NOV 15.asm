# MIPSHW1
# Mingwei Zhang
# 11/13/2023
# Program1

.data
	prompt_int: .asciiz "Enter a integer in the range [100, 200]: " 
	invalid: .asciiz "The input is not in the range. Exiting...\n"
	result: .asciiz "The input is within range [100,200]. The value is "
	new_line: .asciiz "\n"

.text

main:
#Print string from prompt1
	li $v0, 4		#print string system call		
	la $a0, prompt_int
	syscall	
#Read int from prompt1
	li $v0, 5		# read integer system call
	syscall			
	move $t1, $v0		#integer stored into $t1 (int 1)
#Input check for prompt1
	li $t2, 100		# Load immediate value 100 into $t2
	slt $t0, $t1, $t2 	# Set $t0 to 1 if $t1 < 100, 0 otherwise
	bne $t0, $zero, exit

	li $t3, 200		# Load immediate value 200 into $t3
	sle  $t0, $t1, $t3 	# Set $t0 to 1 if $t1 < 200, 0 otherwise
	beq $t0, $zero, exit


# Print Result
	j print		

print:
	li $v0, 4		# print string system call 
	la $a0, result
	syscall
	
	li $v0, 1		# print integer system call 
	move $a0, $t1
	syscall
	
	li $v0, 4		# print string system call 
	la $a0, new_line
	syscall
	
	j main		# repeat by jump to "main" function

exit: 
	li $v0, 4
	la $a0, invalid
	syscall
	
	li $v0, 10
	syscall


	
