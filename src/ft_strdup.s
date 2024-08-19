section .text
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup

ft_strdup:
	push rdi ; Push the content of rdi in the stack. Otherwise, we will probably lose it : Much more secure than giving it to a tmp register we may use in an other function

	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc

	cmp rax, 0
	je .error

	mov rdi, rax
	pop rsi ; Get back the first element of the stack to rsi => What we pushed earlier.
	call ft_strcpy

	ret

.error:
	neg rax
	mov rdi, rax
	call __errno_location
	xor rax, rax
	ret