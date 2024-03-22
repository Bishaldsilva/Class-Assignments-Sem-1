	.file	"search.c"
	.section .rdata,"dr"
LC0:
	.ascii "%d found at index %d\12\0"
LC1:
	.ascii "Element not found\0"
	.text
	.globl	_linear_search
	.def	_linear_search;	.scl	2;	.type	32;	.endef
_linear_search:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L2
L4:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	16(%ebp), %eax
	jne	L3
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$1, -12(%ebp)
L3:
	addl	$1, -16(%ebp)
L2:
	movl	-16(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L4
	cmpl	$0, -12(%ebp)
	jne	L6
	movl	$LC1, (%esp)
	call	_puts
L6:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_binary_search
	.def	_binary_search;	.scl	2;	.type	32;	.endef
_binary_search:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	movl	$0, -20(%ebp)
	jmp	L8
L12:
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	16(%ebp), %eax
	jne	L9
	movl	-24(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$1, -20(%ebp)
	jmp	L10
L9:
	movl	-24(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	16(%ebp), %eax
	jle	L11
	movl	-24(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	jmp	L8
L11:
	movl	-24(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
L8:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jl	L12
L10:
	cmpl	$0, -20(%ebp)
	jne	L14
	movl	$LC1, (%esp)
	call	_puts
L14:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC2:
	.ascii "Enter the size of the array\0"
LC3:
	.ascii "%d\0"
LC4:
	.ascii "Enter the values\0"
	.align 4
LC5:
	.ascii "1 for linear search\12"
	.ascii "2 for binary search\0"
LC6:
	.ascii "Enter your operation\0"
	.align 4
LC7:
	.ascii "Enter the value you want to search...\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$52, %esp
	call	___main
	movl	$LC2, (%esp)
	call	_puts
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	-32(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -16(%ebp)
	sall	$2, %eax
	leal	3(%eax), %edx
	movl	$16, %eax
	subl	$1, %eax
	addl	%edx, %eax
	movl	$16, %ecx
	movl	$0, %edx
	divl	%ecx
	imull	$16, %eax, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	12(%esp), %eax
	addl	$3, %eax
	shrl	$2, %eax
	sall	$2, %eax
	movl	%eax, -20(%ebp)
	movl	$LC4, (%esp)
	call	_puts
	movl	$0, -12(%ebp)
	jmp	L16
L17:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	addl	$1, -12(%ebp)
L16:
	movl	-32(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	L17
	movl	$LC5, (%esp)
	call	_puts
L22:
	movl	$LC6, (%esp)
	call	_puts
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	-24(%ebp), %eax
	cmpl	$1, %eax
	je	L19
	cmpl	$2, %eax
	je	L20
	jmp	L23
L19:
	movl	$LC7, (%esp)
	call	_puts
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	-28(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_linear_search
	jmp	L21
L20:
	movl	$LC7, (%esp)
	call	_puts
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	-28(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_binary_search
	jmp	L21
L23:
	movl	$0, (%esp)
	call	_exit
L21:
	jmp	L22
	.cfi_endproc
LFE16:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
