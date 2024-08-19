section .text
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup

ft_strdup:
	mov rsi, rdi

	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc

	cmp rax, 0
	je .error

	mov rdi, rax
	call ft_strcpy

	ret

.error:
	neg rax
	mov rdi, rax
	call __errno_location ; We need errno => errno_location put the address of errno in rax.
	xor rax, rax
	ret