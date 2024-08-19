section .text
	extern __errno_location
	global ft_write

ft_write:
	mov rax, 1 ; Syscall 1 = write
	syscall
	cmp rax, 0
	jl .error
	ret

.error:
	neg rax
	mov rdi, rax
	call __errno_location ; We need errno => errno_location put the address of errno in rax.
	mov [rax], rdi
	mov rax, -1
	ret

; About errno - man 2 syscalls
; system calls indicate a failure by returning a negative error
; number to the caller on architectures without a separate error
; register/flag, as noted in syscall(2); when this happens, the
; wrapper function negates the returned error number (to make it
; positive), copies it to errno, and returns -1 to the caller of
; the wrapper.