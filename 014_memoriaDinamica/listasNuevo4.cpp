//vamos a sacar, no recorrer, pq el ejercicio lo dice. 

struct Nodo{
	Alu info;
	Nodo* sig;
}
struct Alu{
	int legajo;
	int curso;
	char apellido[50];
}

void apareo (Nodo* &listA, Nodo* &listB, Nodo* &listC){
	//no hace falta que cree auxiliar, pq no me importa conservar las listas


	while(listA != NULL && listB != NULL){

		if(listA->info.legajo < listB->info.legajo){
			agregarNodo(listC, eliminarPrimerNodo(listA)); //eliminarPrimerNodo me devuelve un tipo Alu
		}else{
			agregarNodo(listC, eliminarPrimerNodo(listB));	//agregarNodo(listC,auxB->info);si quiero conservar, uso auxiliares y aca esto auxB->info
		}

	}
	while(listA != NULL){
		agregarNodo(listC, eliminarPrimerNodo(listA));
	}

	while(listB != NULL){
		agregarNodo(listC, eliminarPrimerNodo(listB));
	}
}