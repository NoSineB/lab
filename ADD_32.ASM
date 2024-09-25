
data segment
abc dw 1234h, 5678h
def dw 8060h, 0B020h
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
clc
add ax,bx

mov result, ax

mov ax, abc
mov bx, def
adc ax,bx

mov result+2,ax

adc dx,00h

mov result+4,dx
mov ah,4ch

int 3
code ends
end start
