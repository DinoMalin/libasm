section .text
	global ft_strlen

ft_strlen:
	xor rax, rax		; rax is the register in which we store the return value. We set it to zero.

.loop:
	cmp byte[rdi], 0	; compare the curr byte with 0.  byte get the byte stored at the adress pointed by rdi.
	je .done			; je = jump if equal = jz = jump if zero => if the previous test gives 0, jump to the label .done
	inc rdi				; increment rdi = increment the pointer to get to the next char
	inc rax				; increment rax = increment the return value (works like a counter)
	jmp .loop			; goes to the .loop label again, not exactly like recursive because it will not continue the function afterward but similar.

.done:
	ret					; return : Function is over.