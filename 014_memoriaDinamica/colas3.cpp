void generar3ra(Nodo* &colaAFte, Nodo* &colaAFin, Nodo* &colaBFte, Nodo* &colaBFin, Nodo* &colaCFte, Nodo* &colaCFin){

		while(colaAFte != NULL){
			encolar(colaCFte, colaCFin, desencolar(colaAFte, colaAFin));
		}
		while(colaBFte != NULL){
			encolar(colaCFte, colaCFin, desencolar(colaBFte, colaBFin));
		}
		return;
}