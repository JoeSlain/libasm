section .text

global _ft_strlen

_ft_strlen:
	mov rax, rdi
count:
	cmp byte [rax], 0
	je finished
	inc rax
	jmp count
finished:
	sub rax, rdi
	ret
	
