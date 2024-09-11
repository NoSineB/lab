data segment
a dw 06H
b dw 02H
data ends

code segment
assume cs:code,ds:data
MOV AX,data
MOV DS,AX
START:
MOV AX,a
MOV BX,b
SUB AX,BX
int 3H
code ends
END START
