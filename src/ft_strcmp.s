section .text
	global ft_strcmp

ft_strcmp:
.loop:
	cmp byte[rdi], 0
	je .done
	cmp byte[rsi], 0
	je .done
	mov dl, byte[rsi]
	cmp byte[rdi], dl
	jne .done
	inc rdi
	inc rsi

.done:
	movzx rax, byte[rdi]
	movzx rdx, byte[rsi]
	sub rax, rdx
	ret