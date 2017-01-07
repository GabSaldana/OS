typedef struct pila{
int tope;
void **eltos;
} Pila;


Pila *crearpila(int n){
	Pila *nvo;
	nvo=(Pila*)malloc(sizeof(Pila));
	nvo->tope=0;
	nvo->eltos = (void **)malloc(n*sizeof(void *));
	return nvo;
}

void push(Pila *p,void *dato){
	p->eltos[p->tope]=dato;
	p->tope++;
}

void *top(Pila *p){
	return p->eltos[p->tope-1];
}

void *pop(Pila *p){
	p->tope--;
	return p->eltos[p->tope];
}

int empty(Pila *p){
	return p->tope==0;
}

char *crearChar(char c){
	char *nvo;
	nvo=(char*)malloc(sizeof(char));
	*nvo=c;
	return nvo;
}

int *creaint(int n){
	int *nvo;
	nvo=(int*)malloc(sizeof(int));
	*nvo = n;
	return nvo;
}
