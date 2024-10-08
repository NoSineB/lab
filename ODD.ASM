data segment
a db 06h
e db 'Even $'
o db 'Odd $'
data ends

code segment
assume cs:code, ds:data
start:
mov ax, data
mov ds, ax
mov ax, 0000h
mov al, a
mov bl, 02h
div bl
cmp ah, 00h
jz li
mov dx, offset 0
jmp exit
li:
mov dx, offset e
exit:
mov ah , 09h
int 21h
mov ah, 04h
int 21h
code ends
end start
