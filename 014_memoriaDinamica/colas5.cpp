struct Nodo{
	Alu info;
	Nodo* sig;
}
struct Alu{
	int legajo;
	int curso;
	char apellido[50];
}

//apareo, asi que asumo que las colas estan ordenadas

void apareo(Nodo* &colaAFte, Nodo* &colaAFin, Nodo* &colaBFte, Nodo* &colaBFin, Nodo* &colaCFte, Nodo* &colaCFin){
	//while grande, dos condiciones. 
	while(colaAFte != NULL && colaBFte != NULL){
		if(colaAFte->info.legajo < colaBFte->info.legajo){
			encolar(colaCFte, colaCFin, desencolar(colaAFte, colaAFin)); //encolar(ppio, fin, valor). En pilas y listan no hay ppio y fin, solo tengo un ppio.
		}else{
			encolar(colaCFte, colaCFin, desencolar(colaBFte, colaBFin));
		}
	}
	//ahora, necesito dos whiles, por si salí antes de alguno.
	while(colaAFte != NULL){
		encolar(colaCFte, colaCFin, desencolar(colaAFte, colaAFin));
	}
	while(colaBFte != NULL){
		encolar(colaCFte, colaCFin, desencolar(colaBFte, colaBFin));
	}
}