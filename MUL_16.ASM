data segment
a dw 03H
b dw 02H
data ends

code segment
assume cs:code,ds:data
MOV AX,data
MOV DS,AX
START:
MOV AX,a
MOV BX,b
MUL BX
int 3H
code ends
END START
