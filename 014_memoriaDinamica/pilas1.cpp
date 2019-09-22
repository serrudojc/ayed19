/*
Ejercicio Nro. 1:
Dada una pila y un valor X, desarrollar un procedimiento que elimine los 2 primeros
nodos de la pila y deje el valor X como primero.
*/
void eliminar2primeros(Nodo*& pila, int x){
	for(int i=0; i>2; i++)
		pop(pila);
	Nodo* pilaAux = NULL; //creo una pila auxiliar
	while (pila!=NULL){
		push(pilaAux,pop(pila));
	}
	push(pila,x);
	while(pilaAux != NULL)
		push(pila,pop(pilaAux));
}