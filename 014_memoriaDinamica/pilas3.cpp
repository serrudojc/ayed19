/*
Ejercicio Nro. 3:
Dada una pila y dos valores X e Y, desarrollar un procedimiento que inserte el valor X
en la posición Y de la pila si es posible.
*/
void insertarEnPosicion (Nodo* &pila, int valX, int posY){
	Nodo* pilaAux = NULL;
	int contador = 0;

	//paso a la pila auxiliar
	while(pila != NULL){
		push (pilaAux, pop(pila));
		contador++;
	}

	//chequeo si existe la posicion
	// la posicion la tomamos que empieza de 1
	if (contador >= posY){
		//paso todos hasta la posicion que tengo que insertar
		for(int i=0; i<posY; i++){
			push (pila, pop(pilaAux));
		}

		push(pila, valX);
		//hago while con los push que queden
		while(pilaAux != NULL){
			push(pila, pop(pilaAux));
		}
	}else{
		cout<<"No se puede Insertar"<<endl;
		//si entro por el else, pila va apuntar a NULL. pq hice pop de todo, no punta a nada
		//tengo que volver a pasar todos los valores
		while( pilaAux != NULL){
			pila(pila, pop(pilaAux));
		}
	}	
}