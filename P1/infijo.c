#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct narb //estructura de árbol
{
	void *dato;
	struct narb *izq;
	struct narb *der;
};typedef struct narb Narb;



Narb *carb(Narb *izq,Narb *der,void *dato)
{
	Narb *nvo;
	nvo=(Narb*)malloc(sizeof(Narb));
	nvo->dato = dato;
	nvo->izq = izq;
	nvo->der = der;
	return nvo;
}

int evalA(Narb *p)
{
	char c = *(char*)(p->dato);
	if(p->der==NULL&&p->izq==NULL)
	{
		return c;
	}
	
	if(c=='+')
	{
	return evalA(p->izq)+evalA(p->der);
	}
	if(c=='*')
	{
	return evalA(p->izq)*evalA(p->der);
	}
	if(c=='/')
	{
	return evalA(p->izq)/evalA(p->der);
	}
	if(c=='-')
	{
	return evalA(p->izq)-evalA(p->der);
	}
}

struct nodo//Estructura del nodo
{
 void *dato;
 struct nodo *sig;
};

typedef struct nodo Nodol;

Nodol *creanodo(void *dato,Nodol *sig)//Crear un nodo
{
Nodol *nvo;
nvo=(Nodol*)malloc(sizeof (Nodol) );
nvo->dato = dato;
nvo->sig = sig;
return nvo;
}

void imprime(Nodol *cab, void(*f)(void *))//imprime un nodo;
{
   Nodol *p;
   if(!cab)
   {
   	printf("Lista vacia");
   	return ;
   }
   for(p=cab;p;p=p->sig)
   {
   	(*f)(p->dato);
   }
}


void remueve(Nodol **cab,Nodol *p)//remover un nodo 
{
  Nodol *q;
  
  if(!(*cab))return ;
  
  if(*cab==p)
  {
 	 *cab=p->sig;
  	  p->sig=(Nodol *)NULL;
  	  return;
  }
  
  for(q=*cab;q;q=q->sig)
     {
       if(q->sig==p)break;
     }
      q->sig=p->sig;
      p->sig=(Nodol *)NULL;
}


Nodol *find(Nodol *cab,void *key,int(*cmp)(void *,void *))//encontrar un valor.
{
Nodol *p;
for(p=cab;p;p=p->sig)
   {
   if(!(*cmp)((void *)p->dato,key))
        { 	
   		return p;
   		}
   }
   return (Nodol *)NULL;
}

void insertain(Nodol **cab,void *dato)//Insertar un valor al inicio.
{
*cab = creanodo(dato,*cab);
}


Nodol *copial(Nodol *cab)//Copia superficial.
{
	Nodol *p;
	Nodol *cab2 = NULL;
	for(p=cab;p;p=p->sig)
	{
		cab2 = creanodo(p->dato,cab2);
	}
	return cab2;
}


Nodol *copiapf(Nodol *cab,void *(*f)(void*))//copia profunda.
{
	Nodol *p;
	Nodol *cab2 = NULL;
	for(p=cab;p;p=p->sig)
		{
	    cab2 = creanodo( (*f)(p->dato),cab2);
		}
	return cab2;
}


struct pila
{
int tope;
void **eltos;
};

typedef struct pila Pila;

Pila *crearpila(int n)
{
Pila *nvo;
nvo=(Pila*)malloc(sizeof(Pila));
nvo->tope=0;
nvo->eltos = (void **)malloc(n*sizeof(void *));
return nvo;
}


void push(Pila *p,void *dato)//función para ingresar un dato.
{
p->eltos[p->tope]=dato;
p->tope++;
}

void *top(Pila *p)//función para imprimir el último valor;
{
return p->eltos[p->tope-1];
}


void *pop(Pila *p)//función para sacar valores
{
p->tope--;
return p->eltos[p->tope];
}

int empty(Pila *p)//función para sacar valores
{
return p->tope==0;
}

char *crearChar(char c)//Crear caracter.
{
char *nvo;
nvo=(char*)malloc(sizeof(char));
*nvo=c;
return nvo;
}

int *creaint(int n)
{
	int *nvo;
	nvo=(int*)malloc(sizeof(int));
	*nvo = n;
	return nvo;
}

char ap[1];
int i;

char stack[100];
char sufijo[100];
char infijo[100];
int value( char c)
{
	if( c == '^' )
		return 3;
	if( c == '*' || c == '/')
		return 2;
	if( c == '+'|| c == '-')
		return 1;
	return 0;
}

void transforma(char vacia[] ,  char cadena[])
{
	char temp;
	int i = 0 ;
	int indx = 0;
	int tope = 1; 
	for( i = 0; cadena[i] ; i++)
	{
		if( cadena[i] == '(' )
		{
			stack[tope] = '(';
			tope++;
			continue;
		}


		if( cadena[i] >= '0' && cadena[i]<='9' )// vemos si es un dígito
		{
			// Agregamos a la cadena posfija
			vacia[indx] = cadena[i];
			indx++;
			vacia[indx] = 0;
			continue;
		}

		if( cadena[i] == ')' )
		{
			// Vaciamos la pila hasta encontrar (
			while( stack[tope-1]!='(')
			{
				vacia[indx] = stack[tope-1];
				indx++;
				tope--;
				vacia[indx] = 0;
				stack[tope] = 0;
			}
			tope--;
			stack[tope] = 0;
			continue;
		}

		if( value ( cadena[i] ) > value(stack[tope-1]) )
		{
			stack[tope] = cadena[i];
			tope++;
			continue;
		}



		if( value(cadena[i]) == value(stack[tope-1]) )
		{
			vacia[indx] = stack[tope-1];
			indx++;
			vacia[indx] = 0;
			stack[tope-1] = cadena[i];
			continue;
		}

		if( value(cadena[i]) < value(stack[tope-1]) )
		{
			while(stack[tope-1]!='('&& tope!=1 )
			{
				vacia[indx] = stack[tope-1];
				indx++;
				tope--;
				stack[tope] = 0;
				vacia[indx] = 0;
			}
			stack[tope] = cadena[i];
			tope++;
		}
	}
	while(tope!=1)
	{
		vacia[indx] = stack[tope-1];
		indx++;
		tope--;
		stack[tope] = 0;
		vacia[indx] = 0;				
	}
}


int main()
{
	Pila *num=crearpila(1000);
	Narb *p=(Narb*)NULL;
	printf("Ingresa una expresión en infijo: ");
	scanf("%s",infijo);
	transforma(sufijo,infijo);
	for(i=0;sufijo[i];i++)
	{
		if(sufijo[i]>47&&sufijo[i]<58)
        {
		ap[0]=sufijo[i];
		push(num , carb(  (Narb*)NULL ,   (Narb*)NULL ,  creaint(atoi(ap))  ) );
		continue;
		}
		push(num,carb( (Narb*)pop(num),(Narb*)pop(num),&sufijo[i]));
	}
	i = evalA( (Narb*)top(num));
	printf("Expresión en postfijo: %s\n",sufijo);
	printf("Evaluando el postfijo es: %d",i);
}


//55+4*2/
