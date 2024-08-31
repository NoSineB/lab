data segment
a db 03H
b db 02H
data ends

code segment
assume cs:code,ds:data
MOV AX,data
MOV DS,AX
START:
MOV AL,a
SUB AL,b
int 3H
code ends
END START

/*
AX=0701 BX=0000 CX=001D	SP=0000 BP=0000 SI=0000 D1=0000

076A:0000 03 02 00 00 00 00 00 00-00 00 00 00 00 00 00 00 
*/
