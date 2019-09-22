/*
Ejercicio Nro. 2:
Dadas dos listas LISTA y LISTB, desarrollar un procedimiento que genere una
única lista LISTC a partir de ellas. (Primero los nodos de LISTA y luego los de
LISTB).
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

void generar3ra(Nodo* listA, Nodo* listB, Nodo* &listC){
	Nodo* auxA = listA;
	Nodo* auxB = listB;

	while(auxA != NULL){
		agregarNodo (listC, auxA->info);
		auxA = auxA->sig;
	}
	while(auxB != NULL){
		agregarNodo(listC, auxB->info);
		auxB = auxB->sig;
	}
}