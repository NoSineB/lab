
data segment
abc dd 12345678h
def dd 8060B020h
ghi dw ?
data ends
 
code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
mov dl,00h
mov ax, word ptr abc
mov bx, word ptr def
add ax,bx

mov si,ax

mov ax, word ptr abc+2
mov bx, word ptr def+2
adc ax,bx

mov di,ax
mov ax,0000h

int 3
code ends
end start
