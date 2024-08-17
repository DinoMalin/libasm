section .text
	global ft_strcpy

ft_strcpy:
	mov rax, rdi ; return value is dest address : we can move it right now to rax

.loop:
	mov dl, byte[rsi]
	mov byte[rdi], dl
	cmp byte[rsi], 0
	je .done
	inc rsi
	inc rdi
	jmp .loop

.done:
	ret