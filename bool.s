	.file	"bool.c"
	.text
	.section	.rodata
.LC0:
	.string	"a > b: %d; a < b %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -16(%rbp)
	movl	$4, -12(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
