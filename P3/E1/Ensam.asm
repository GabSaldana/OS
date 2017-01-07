segment .data
cadena db 'Programado en ensamblador para LInux',0XA
segment .text
	global _start
_start:
	mov edx,38d
	mov ecx,cadena
	mov ebx,1
	mov eax,4
	int 0X80
	mov eax,1
	int 0x80

