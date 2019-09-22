/*
Ejercicio Nro. 4:
Dada una cola, imprimirla en orden natural si tiene más de 100 nodos, caso contrario
imprimirla en orden inverso.
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

void imprimirNodos(Nodo* &colaFte, Nodo* & colaFin){
	int cantNodos = contarNodos(colaFte, colaFin);
	Alu valor;

	Nodo* pila = NULL;

	if(cantNodos>100){
		//natural, uso desencolar
		while(colaFte != NULL){
			valor = desencolar(colaFte, colaFin);
			cout<<valor.legajo<<endl;
			cout<<valor.curso<<endl;
			cout<<valor.apellido<<endl;
		}
	}else{
		//orden inverso, uso la pila creada
		while(colaFte != NULL){
			push(pila, desencolar(colaFte, colaFin));
		}
		while(pila != NULL){
			valor = pop(pila); //saco de la pila
			cout<<valor.legajo<<endl;
			cout<<valor.curso<<endl;
			cout<<valor.apellido<<endl;	
		}
	}
}