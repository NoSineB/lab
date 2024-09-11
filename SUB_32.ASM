
data segment
abc dd 87654321h
def dd 11111111h
data ends
 
code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
mov dl,00h
mov ax, word ptr abc
mov bx, word ptr def
sub ax,bx

mov si,ax

mov ax, word ptr abc+2
mov bx, word ptr def+2
sbb ax,bx

mov di,ax
mov ax,0000h

int 3
code ends
end start
