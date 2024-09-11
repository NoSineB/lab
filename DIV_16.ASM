data segment
a dw 0AAABH
b dw 5555H
data ends

code segment
assume cs:code,ds:data
MOV AX,data
MOV DS,AX
START:
MOV AX,00
MOV AX,a
MOV BX,b
DIV BX
int 3H
code ends
END START
