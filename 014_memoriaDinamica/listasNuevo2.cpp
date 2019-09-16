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