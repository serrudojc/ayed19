/*
Ejercicio Nro. 4:
Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila modificada.
En caso de no haber ningún valor igual a X retornar la pila sin cambio.
*/
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