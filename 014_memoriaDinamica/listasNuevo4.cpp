//vamos a sacar, no recorrer, pq el ejercicio lo dice. 
/*
Ejercicio Nro. 4:
Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere otra lista LISTC 
por apareo del campo LEGAJO del registro (define orden creciente en ambas).
Nota: LISTA y LISTB dejan de ser útiles después del apareo.
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

void apareo (Nodo* &listA, Nodo* &listB, Nodo* &listC){
	//no hace falta que cree auxiliar, pq no me importa conservar las listas

	while(listA != NULL && listB != NULL){
		if(listA->info.legajo < listB->info.legajo)
			agregarNodo(listC, eliminarPrimerNodo(listA)); //eliminarPrimerNodo me devuelve un tipo Alu
		else
			agregarNodo(listC, eliminarPrimerNodo(listB));	//agregarNodo(listC,auxB->info);si quiero conservar, uso auxiliares y aca esto auxB->info
	}
	while(listA != NULL)
		agregarNodo(listC, eliminarPrimerNodo(listA));
	
	while(listB != NULL)
		agregarNodo(listC, eliminarPrimerNodo(listB));
}