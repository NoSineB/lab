
data segment
abc dw 8765h, 4321h
def dw 1111h, 1411h
result dw 3 dup (?) 
data ends
 
code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
mov dx,00h
mov ax, abc+2
mov bx, def+2
sub ax,bx
mov result, ax

mov ax, abc
mov bx, def
sbb ax,bx

mov result+2,ax
sbb dx,00h
mov result+4,dx
mov ah,4ch

int 3
code ends
end start
