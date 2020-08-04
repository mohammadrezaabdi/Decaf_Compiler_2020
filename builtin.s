.text

_Alloc: #one integer parameter, returns address of heap­allocated memory of that size in bytes (in $v0)
	# To use this function, first you should push the byte size you need for allocation from heap

	addi	$sp, $sp, -4	# push needed registers
	sw	$a0, 0($sp)

	lw	$a0, 4($sp)
	li	$v0, 9
	syscall

	lw	$a0, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra

_StringEqual: #two string parameters, returns 1 if strings are equal and 0 otherwise (in $v0)
	# To use this function, first you should push the string addresses which has null trminated with '\0'

	addi	$sp, $sp, -4	# push needed registers
	sw	$a0, 0($sp)
	addi	$sp, $sp, -4
	sw	$a1, 0($sp)
	addi	$sp, $sp, -4
	sw	$t0, 0($sp)
	addi	$sp, $sp, -4
	sw	$t1, 0($sp)
	addi	$sp, $sp, -4
	sw	$t2, 0($sp)

	lw	$a0, 20($sp)
	lw	$a1, 24($sp)

_compare_loop:
	lb	$t0, 0($a0)
	lb	$t1, 0($a1)

	add	$t2, $t1, $t0
	beqz	$t2, _str_equal
	beqz	$t0, _str_not_equal
	beqz	$t1, _str_not_equal
	addi	$a0, $a0, 1
	addi	$a1, $a1, 1
	beq	$t1, $t0, _compare_loop

_str_not_equal:
	li	$v0, 0
	j	_str_cmp_exit

_str_equal:
	li	$v0, 1

_str_cmp_exit:
	lw	$t2, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4
	lw	$t1, 0($sp)
	addi	$sp, $sp, 4
	lw	$t0, 0($sp)
	addi	$sp, $sp, 4
	lw	$a1, 0($sp)
	addi	$sp, $sp, 4
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra

_ReadLine: #no parameters, returns string read from user input
	#returns the address of input string returns in $v0

	addi	$sp, $sp, -4	# push needed registers
	sw	$a0, 0($sp)
	addi	$sp, $sp, -4
	sw	$t1, 0($sp)
	addi	$sp, $sp, -4
	sw	$t0, 0($sp)

	la	$t0, _BUFFER
	li	$a0, 0
_read_loop:
	li	$v0, 12
	syscall
	beq	$v0, 10, _copy_read		# '\0'
	sb	$v0, 0($t0)
	addi	$a0, $a0, 1
	addi	$t0, $t0, 1
	j	_read_loop

_copy_read:
	li	$v0, 0
	sb	$v0, 0($t0)  # insert '\0' at the end of string

	li	$v0, 9		# allocation new memory for string
	syscall
	move	$v1, $v0

	la	$t0, _BUFFER
_copy_loop:
	lb	$t1, 0($t0)	#copy into new space of memory
	sb	$t1, 0($v1)
	addi	$a0, $a0, -1
	addi	$v1, $v1, 1
	addi	$t0, $t0, 1
	bnez	$a0, _copy_loop

_read_finished:
	lw	$t0, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4
	lw	$t1, 0($sp)
	addi	$sp, $sp, 4
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra

	.data
_BUFFER:.space 1000

_ReadInteger: #no parameters, returns integer read from user input
	#returns the decimal value in $v0

	addi	$sp, $sp, -4	# push needed registers
	sw	$t0, 0($sp)
	addi	$sp, $sp, -4
	sw	$t1, 0($sp)
	addi	$sp, $sp, -4
	sw	$t2, 0($sp)

	li	$t0, 0		# decimal number
	li	$t1, 0		# flag register : non=0 pos=1 neg=2 hex=3
	li	$t2, 0		# digit counter

_read_int_loop:
	li	$v0, 12
	syscall

	beq	$v0, 32, _int_ready	#' '
	beq	$v0, 10, _int_ready	#'\n'

	bne	$t2, 1, _sign_check 	# check for 0x 0X
	beq	$v0, 88, _hex_int	#'X'
	beq	$v0, 120, _hex_int	#'x'
	j	_after_sign
_hex_int:
	bnez	$t0, _read_int_err
	bnez	$t1, _read_int_err
	addi	$t1, $t1, 3
	j	_read_int_loop

_sign_check:
	bnez	$t2, _after_sign	# check for + -
	beq	$v0, 43, _positive	#'+'
	beq	$v0, 45, _negetive	#'-'
	j	_after_sign
_negetive:
	addi	$t1, $t1, 2
	j	_read_jump
_positive:
	addi	$t1, $t1, 1
	j	_read_jump

_after_sign:
	bne	$t1, 3, _decimal

_visit_a:
	beq	$v0, 65, _visit_A	#'A'
	bne	$v0, 97, _visit_b	#'a'
_visit_A:
	li	$v0, 10
	j	_hexadecimal

_visit_b:
	beq	$v0, 66, _visit_B	#'B'
	bne	$v0, 98, _visit_c	#'b'
_visit_B:
	li	$v0, 11
	j	_hexadecimal

_visit_c:
	beq	$v0, 67, _visit_C	#'C'
	bne	$v0, 99, _visit_d	#'c'
_visit_C:
	li	$v0, 12
	j	_hexadecimal

_visit_d:
	beq	$v0, 68, _visit_D	#'D'
	bne	$v0, 100, _visit_e	#'d'
_visit_D:
	li	$v0, 13
	j	_hexadecimal

_visit_e:
	beq	$v0, 69, _visit_E	#'E'
	bne	$v0, 101, _visit_f	#'e'
_visit_E:
	li	$v0, 14
	j	_hexadecimal

_visit_f:
	beq	$v0, 70, _visit_F	#'F'
	bne	$v0, 102, _visit_decimal#'f'
_visit_F:
	li	$v0, 15
	j	_hexadecimal

_visit_decimal:
	subi	$v0, $v0, 48		#'0'
	bgt	$v0, 9, _read_int_err
	blt	$v0, 0, _read_int_err

_hexadecimal:
	bge	$t2, 9, _read_int_err
	sll	$t0, $t0, 4
	add	$t0, $t0, $v0
	j	_read_jump

_decimal:
	subi	$v0, $v0, 48		#'0'
	bgt	$v0, 9, _read_int_err
	blt	$v0, 0, _read_int_err
	mul	$t0, $t0, 10
	add	$t0, $t0, $v0
	bltz	$t0, _read_int_err 	# overflow detection
_read_jump:
	addi	$t2, $t2, 1
	j	_read_int_loop

_int_ready:
	move	$v0, $t0
	bne	$t1, 2, _read_int_end
	neg	$v0, $v0
	j	_read_int_end

_read_int_err:
	li	$v0, 0

_read_int_end:
	lw	$t2, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4
	lw	$t1, 0($sp)
	addi	$sp, $sp, 4
	lw	$t0, 0($sp)
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra


_PrintInteger: #one integer parameter, prints that number to the console
	# To use this function, first you should push the integer value

	addi	$sp, $sp, -4	# push needed registers
	sw	$a0, 0($sp)

	lw	$a0, 4($sp)
	li	$v0, 1
	syscall

	lw	$a0, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra

_PrintDouble: #one double parameter, prints that number to the console
	# To use this function, first you should push the double value (2 words)
	# at first you should be in main processor
	#TODO: better rounding impeletation

	addi	$sp, $sp, -4	# push needed registers
	s.s	$f12, 0($sp)
	addi	$sp, $sp, -4
	s.s	$f13, 0($sp)
	addi	$sp, $sp, -4
	s.s	$f0, 0($sp)
	addi	$sp, $sp, -4
	s.s	$f1, 0($sp)
	addi	$sp, $sp, -4
	sw	$t0, 0($sp)
	addi	$sp, $sp, -4
	sw	$t1, 0($sp)
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
	addi	$sp, $sp, -4
	sw	$a1, 0($sp)

	l.s	$f13, 32($sp)
	l.s	$f12, 36($sp)

	li	$t1, 0x40C38800 # 10000.0 in double
	li	$t0, 0x00000000
	mtc1.d 	$t0, $f0
	mul.d	$f12, $f12, $f0
	cvt.w.d	$f12, $f12
	mfc1.d	$t0, $f12
	div	$a0, $t0, 10000	# print exponent
	li	$v0, 1
	syscall
	move	$a1, $a0
	li	$a0, 46		#'.'
	li	$v0, 11
	syscall
	mul	$a1, $a1, 10000	# print mantissa
	sub	$a0, $t0, $a1
	li	$v0, 1
	syscall

	lw	$a1, 0($sp)	 # pop needed registers
	addi	$sp, $sp, 4
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4
	lw	$t1, 0($sp)
	addi	$sp, $sp, 4
	lw	$t0, 0($sp)
	addi	$sp, $sp, 4
	l.s	$f1, 0($sp)
	addi	$sp, $sp, 4
	l.s	$f0, 0($sp)
	addi	$sp, $sp, 4
	l.s	$f13, 0($sp)
	addi	$sp, $sp, 4
	l.s	$f12, 0($sp)
	addi	$sp, $sp, 4

	jr $ra			# Return from function: Jump to addr stored in $ra

_PrintString: #one string parameter, prints that string to the console
  	# To use this function, first you should push the address of null-terminated string

  addi	$sp, $sp, -4	# push needed registers
  sw	$a0, 0($sp)

  lw	$a0, 4($sp)
  li	$v0, 4
  syscall

  lw	$a0, 0($sp)	 # pop needed registers
  addi	$sp, $sp, 4

  jr $ra			# Return from function: Jump to addr stored in $ra

_PrintBool: #one boolean parameter, prints true/false to the console
    	# To use this function, first you should push the boolean integer value

  addi	$sp, $sp, -4	# push needed registers
  sw	$a0, 0($sp)
  addi	$sp, $sp, -4
  sw	$t0, 0($sp)

  lw	$t0, 8($sp)
  beqz	$t0, _print_false
  la	$a0, _TRUE
  j	_print_true

_print_false:
  la	$a0, _FALSE

_print_true:
  li	$v0, 4
  syscall

  lw	$t0, 0($sp)	 # pop needed registers
  addi	$sp, $sp, 4
  lw	$a0, 0($sp)
  addi	$sp, $sp, 4

  jr $ra			# Return from function: Jump to addr stored in $ra

  .data
_TRUE:	.asciiz	"true"
_FALSE:	.asciiz	"false"

_Halt: #no parameters, stop program execution
	li $v0, 10
	syscall
