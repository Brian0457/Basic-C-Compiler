.LC0:
	.string "%d\n"
	.globl println
println:
	movq	%rdi, %rsi
	movq	$0, %rax
	movl	$.LC0, %edi
	jmp	printf
.LC1:
	.string "%d"
	.globl readi
readi:
	subq	$24, %rsp
	movl	$.LC1, %edi
	movq	$0, %rax
	leaq	12(%rsp), %rsi
	movl	$0, 12(%rsp)
	call	__isoc99_scanf
	movl	12(%rsp), %eax
	addq	$24, %rsp
	ret
	.globl main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$4, %rax
	movq	%rax, %rdi
	call	malloc
	pushq	%rax
	call	readi
	pushq	%rax
	movl	$0, %eax
	pushq	%rax
