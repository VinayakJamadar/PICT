%MACRO IO 4
MOV RAX, %1
MOV RDI, %2
MOV RSI, %3
MOV RDX, %4
SYSCALL
%ENDMACRO

section .data
isProtectedMode: dq "Protected Mode",0x0A
len1: equ $-isProtectedMode

isRealMode: dq "Real Mode", 0x0A
len2: equ $-isRealMode

gdt_msg db 10,'GDT: '
gdt_len:equ $-gdt_msg

ldt_msg db 10,'LDT: '
ldt_len:equ $-ldt_msg

idt_msg db 10,'IDT: '
idt_len:equ $-idt_msg

tr_msg db 10,'Task: '
tr_len: equ $-tr_msg

msw_msg db 10,'MSW: '
msw_len:equ $-msw_msg

colmsg db ':'

newLine: db "",0x0A
len: equ $-newLine

section .bss

gdt: resd 1 
ldt: resw 1
idt: resd 1
tr:  resw 1
cr0_data resd 1
Result resb 04

section .text
global _start
_start:
	IO 01, 01, newLine, len
	SMSW rax
	BT rax, 0
	JC l1
	JNC l2
	l1:
		IO 01, 01, isProtectedMode, len1
		JMP GDTR_Printing
	l2:
		IO 01, 01, isRealMode, len2
GDTR_Printing: 
	sgdt [gdt]
 	IO 01, 01, gdt_msg, gdt_len
 
 	mov bx,[gdt+4]
 	call HexToASCII

 	mov bx,[gdt+2]
 	call HexToASCII

 	IO 01, 01, colmsg, 1

 	mov bx,[gdt]
 	call HexToASCII

LDTR_Printing:
 	sldt [ldt]
 	IO 01, 01, ldt_msg, ldt_len
 	mov bx,[ldt]
 	call HexToASCII

IDTR_Printing:
 	sidt [idt]
 	IO 01, 01, idt_msg, idt_len
 
 	mov bx,[idt+4]
 	call HexToASCII

 	mov bx,[idt+2]
 	call HexToASCII

 	IO 01, 01, colmsg, 1

 	mov bx,[idt]
 	call HexToASCII

TR_Printing:
 	str [tr]
 	IO 01, 01, tr_msg, tr_len
 
 	mov bx,[tr]
 	call HexToASCII

 	IO 01, 01, msw_msg, msw_len
 	
  SMSW rax
  mov [cr0_data], rax
  
 	mov bx,[cr0_data+2]
 	call HexToASCII

 	mov bx,[cr0_data]
 	call HexToASCII

 	IO 01, 01, newLine, len

	mov rax, 60
	mov rdi, 00
 	syscall

HexToASCII:
 	mov rsi,Result
 	mov rcx,04 

	continue:
 		rol bx,4
 		mov dl,bl
 		and dl,0fh
 		add dl,30h
 		cmp dl,39h
 		jbe continue2 
 		add dl,07h
		continue2:
 			mov [rsi],dl
 			inc rsi
 			loop continue
 		IO 01, 01, Result, 4 ;printlay the number from buffer
 		ret