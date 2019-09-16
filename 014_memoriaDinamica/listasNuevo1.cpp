int cantidadNodos (Nodo* lista){
	Nodo* aux = lista;
	int contador = 0;

	while(aux != NULL){
		contador++;
		aux = aux->sig;
	}
	return contador;
}