/*
UNA PILA NO SE PUEDE ORDENAR, voy a necesitar una estructura auxiliar.
Uso una LISTA (no un vector, pq no se cuantos elementos tengo)
*/

struct Nodo{
	Alu info;
	Nodo* sgte;
}

struct Alu{
	int leg;
	string NyA;
	string curso;
}

void ordenarPila (Nodo* &pila){
	//usamos uns estrcutura auxiliar para poder ordenar
	//creamos una lista
	Nodo* lista = NULL;

	//
	while (pila != NULL){
		insertarOrdenado(lista, pop(pila));
	}
	//ahora tenemos todo en nuestra lista ordenada, pero ahora tenemos que pasar la lista a la pila
	while (lista != NULL){
		push(pila, eliminarPrimerNodo(lista));
	}
	
}