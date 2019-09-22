/*
Ejercicio Nro. 3:
Dada una LISTA, imprimirla en orden natural si tiene más de 100 nodos, caso
contrario imprimirla en orden inverso.
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

void imprimirNodos (Nodo* lista){
	//veo cuantos nodos hay
	int cantNodos = cantidadNodos(lista);

	//para no perder la referencia, ante la duda meto un aux
	Nodo* aux = lista;

	//creo una pila para el inverso
	Nodo* pila = NULL;
	Alu campoInfo;

	if(cantNodos < 100){
		while(aux != NULL){
			cout<<aux->info.legajo<<endl;
			cout<<aux->info.curso<<endl;
			cout<<aux->info.apellido<<endl;
			aux = aux->sig; //tengo que igualar a sig, pq sino me quedo en el mismo lugar
		}
	}else{
		//inverso
		while(aux != NULL){
			//inserto en la pila
			push(pila, aux->info);
			//avanzo, si no me quedo
			aux = aux->sig;
		}
		//ahora voy imprimiendo la pila 
		while(pila != NULL){
			campoInfo = pop(pila);
			//el pop me devuelve el campo info del nodo
			cout<<campoInfo.legajo<<endl;
			cout<<campoInfo.curso<<endl;
			cout<<campoInfo.apellido<<endl;
		}
	}
}