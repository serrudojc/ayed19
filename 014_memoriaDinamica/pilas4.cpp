void reemplazarXporY (nodo* &pila, int x, int y){
	Nodo* pilaAux = NULL;
	int valor;

	//recorrer para popear
	while (pila != NULL){
		//pop devuelve la parte info del nodo
		valor = pop(pila);
		if (valo == x){
			push(pilaAux,Y);
		}else{
			push(pilaAux,valor);
		}
	}
	while (pilaAux != NULL){
		push (pila, pop(pilaAux));
	}
}