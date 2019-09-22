/*
Ejercicio Nro. 1:
Dada una lista, desarrollar una función que devuelva la cantidad de nodos que
tiene.
*/
struct Nodo{
	Alu info;
	Nodo* sig;
}
struct Alu{
	int legajo;
	int curso;
	char apellido[50];
}

int cantidadNodos (Nodo* lista){
	Nodo* aux = lista;
	int contador = 0;

	while(aux != NULL){
		contador++;
		aux = aux->sig;
	}
	return contador;
}