#include "Elem.h"
#include <stdlib.h>

typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Lista;


Lista vacia(){
	return NULL;
}

Lista cons(Elem e, Lista l){
   Lista t=(Lista)malloc(sizeof(struct Nodo));
   t->dato=e;
   t->sig=l;
   return t;
}
int esvacia(Lista l){
   return l==NULL;
}

Elem cabeza(Lista l){
   return l->dato;
}

Lista resto(Lista l){
   return l->sig;
}

int NumElem(Lista l){
    if(esvacia(l))
	return 0;
    else
	return 1+NumElem(resto(l));
}

void ImpLista(Lista l){
  if(!esvacia(l)){
    ImpElem(cabeza(l));
    ImpLista(resto(l));
   }
}
void ImpLista2(Lista l){
	if(!esvacia(l)){
		ImpLista2(resto(l));
		printf("%d ",cabeza(l));		
	}	
}
Lista Pega(Lista l1, Lista l2){
    if(esvacia(l1))
      return l2;
    else
      return cons(cabeza(l1),Pega(resto(l1),l2));
}

int Igual(Elem e, Elem e2){
	if(e==e2)
		return 1;
	else
		return 0;
}

int Esmenor(Elem e, Elem e2){
	if(e <= e2)
		return 1;
	else
		return 0;
}

Lista InsOrd(Elem e, Lista l){
   if(esvacia(l))
     return cons(e,l);
   else
     if(Esmenor(e,cabeza(l)))
         return cons(e,l);
     else
         return cons(cabeza(l),InsOrd(e,resto(l)));
}

Lista Ordena(Lista l){
	if(esvacia(l))
		return l;
	else
		return InsOrd(cabeza(l),Ordena(resto(l)));
}

int EstaEn(Elem e, Lista l){
	if(esvacia(l))
		return 0;
	else
		if(Igual(e,cabeza(l)))
			return 1;
		else
			return EstaEn(e,resto(l));
}

int Ocurrencias(Elem e, Lista l){
	if(esvacia(l))
		return 0;
	else
		if(Igual(e,cabeza(l)))
			return 1+Ocurrencias(e,resto(l));
		else
			return Ocurrencias(e,resto(l));
}

int SonIguales(Lista l1, Lista l2){
	if(esvacia(l1)&&esvacia(l2))
		return 1;
	else
		if(esvacia(l1)||esvacia(l2))
			return 0;
		else
			if(Igual(cabeza(l1),cabeza(l2)))
				return SonIguales(resto(l1),resto(l2));
			else
				return 0;
}

Lista invierte(Lista l){
	if(!esvacia(l))
		return Pega(invierte(resto(l)),cons(cabeza(l),vacia()));
	else
		return l;
}


