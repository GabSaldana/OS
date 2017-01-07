segment .bss
cadena db 50 ;cadena es un flujo de bytes
segment .text
	 global _start
_start:
	mov edx,50d ;guardando el tamañode la cadena (50)
	mov ecx,cadena ;guardando cadena 
	mov ebx,0 ;file descriptor, a la entrada(teclado)
	mov eax,3 ;read
	int 0X80 ;kernel
	
	;HASTA AQUI YA LEIMOSLACADENA

	mov edx,50d ;tamaño
	mov ecx,cadena ;lo que va a escribir
	mov ebx,1  ;file decriptor, a la salida(terminal)
	mov eax,4 ;write
	int 0X80 ;kernel
	mov eax,1 ;exit
	int 0X80 ;kernel
	
