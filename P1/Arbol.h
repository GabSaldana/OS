typedef struct Arbol{
	void *dato;
	struct Arbol *izq;
	struct Arbol *der;
} Arbol;

Arbol *crearNodo(Arbol *izq, Arbol *der, void *dato){
	Arbol *nvo;
	nvo=(Arbol*)malloc(sizeof(Arbol));
	nvo->dato=dato;
	nvo->izq=izq;
	nvo->der=der;
	return nvo;
}


