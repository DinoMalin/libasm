section .text
	global ft_strlen

ft_strlen:
	xor rax, rax		; rax is the register in which we store the return value. We set it to zero.
	mov rsi, rdi		; To never modifiy rdi, the first arg, we copy it to rsi and work with rsi.

.loop:
	cmp byte [rsi], 0	; compare the curr byte with 0.  byte get the byte stored at the adress pointed by rsi.
	je .done			; je = jump if equal = jz = jump if zero => if the previous test gives 0, jump to the label .done
	inc rsi				; increment rsi = increment the pointer to get to the next char
	inc rax				; increment rax = increment the return value (works like a counter)
	jmp .loop			; goes to the .loop label again, not exactly like recursive because it will not continue the function afterward but similar.

.done:
	ret					; return : Function is over.