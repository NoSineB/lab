data segment
a db 06H
b db 02H
data ends

code segment
assume cs:code,ds:data
MOV AX,data
MOV DS,AX
START:
MOV AH,00
MOV AL,a
MOV BL,b
DIV BL
int 3H
code ends
END START
