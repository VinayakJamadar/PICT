section .data
  str1 db "Enter five 64 bit Hex Numbers.", 0xA
  len1 equ $-str1
  
  str2 db "Entered five 64 bit Hex Numbers are as follows.", 0xA
  len2 equ $-str2
  
  %macro IO 3
    mov rax, %1
    mov rdi, %1
    mov rsi, %2
    mov rdx, %3
    syscall
  %endmacro
  
  cnt db 0
  
section .bss
  numbers resq 5
  
section .text

global _start

_start:
  IO 1, str1, len1
  mov rbx, numbers
  mov byte[cnt], 0x5
  
  loop_for_reading:
    IO 0, rbx, 17
    add rbx, 17
    dec byte[cnt]
    jnz loop_for_reading
  
  IO 1, str2, len2
  mov rbx, numbers
  mov byte[cnt], 0x5
  
  loop_for_printing:
    IO 1, rbx, 17
    add rbx, numbers
    dec byte[cnt]
    jnz loop_for_printing
  
  mov rax, 60
  mov rdi, 00
  syscall