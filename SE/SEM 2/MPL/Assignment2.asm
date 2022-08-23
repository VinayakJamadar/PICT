section .data
  msg1 db "Enter a String : "
  len1 equ $-msg1
  
  msg2 db "Length of String is : "
  len2 equ $-msg2
  
  %macro IO 3
    mov rax, %1
    mov rdi, %1
    mov rsi, %2
    mov rdx, %3
    syscall
  %endmacro
  
  cnt db 0
  len dq 0
  
section .bss
  string resb 20
  
section .text

global _start

_start:

  IO 1, msg1, len1
  IO 0, string, 20
  
  dec rax
  mov rsi, len
  mov byte[cnt], 0x16
  
  label1:
    rol rax, 0x4
    mov bl, al
    and bl, 0xf
    cmp bl, 0x9
    jbe label2
    add bl, 0x7
    
    label2:
      add bl, 0x30
      mov byte[rsi], bl
      inc rsi
      dec byte[cnt]
      jnz label1
  
  IO 1, len, 16
  
  mov rax, 60
  mov rdi, 00
  syscall