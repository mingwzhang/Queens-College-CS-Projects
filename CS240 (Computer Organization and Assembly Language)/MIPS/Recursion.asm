.data
    	result_str: .asciiz "Result: "

.text
main:
	# if (n = 0) return 6  else return 4*Func(n-1) + 5*n;

    	# Initialize input value (e.g., n = 3)
    	li $a0, 2

    	# Call the function
    	jal FCT	

    	# Print the result
    	li $v0, 4           # System call code for print_str
    	la $a0, result_str  # Load address of the result string
    	syscall

    	li $v0, 1           # System call code for print_int
    	move $a0, $s0       # Load the result from $s0
    	syscall

    	# Exit program
    	li $v0, 10          # System call code for exit
    	syscall

FCT:
	#prologue
	addi $sp, $sp, -8		# sp = start pointer
	sw $a0, 0($sp)			# sw = store word
	sw $ra, 4($sp)
	
	#base
	li $v0, 6
	beq $a0, $zero, Done		# do not give branch with number
					# branch has two registers
	#recursive
	addi $a0, $a0, -1 		# $a0 ← n - 1
	jal FCT				# FCT(n-1)
	move $t0, $v0			#$t0 ← return value of Func FCT(n-1)
	sll $t0, $t0, 2			#$t0 ← 4 * FCT(n-1)

	li $t1, 5			#$t1 ← 5
	lw $t2, 0 ($sp)			#$t2 ← n
	mul $t1, $t1, $t2		#$t1 ← 5n

	add $v0, $t0, $t1		#$v0 ← 4*Func(n-1) + 5*n
	move $s0, $v0			#$s0 ← read int

	#epilogue
	Done:
	lw $a0, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra

