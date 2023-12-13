.data
array:  .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
spaces: .asciiz "  "
result: .asciiz "\nTotal element is "

.text
	la $t0, array           #initialize array $t0
	li $t2, 0		#variable for counting element $t2

LOOP:				
 	lw $t1, 36($t0)		#size of array 4 * (10-1) bytes
 	beq $t1, $zero, EXIT	#array exit if 0
 	move $a0, $t1            
	li $v0, 1    
	syscall			

	la $a0, spaces        
	li $v0, 4              
	syscall

	subi  $t0, $t0, 4	#subtract array size by 4 bytes
	addi $t2, $t2, 1 	#add 1 for element count
	j LOOP			
				
EXIT:				
	li $v0, 4		
	la $a0, result		
	syscall			
				
	li $v0, 1		 
	move $a0, $t2		
	syscall			
				
    	li $v0, 10              
    	syscall
