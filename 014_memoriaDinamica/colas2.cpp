/*
Ejercicio Nro. 2:
Dada una cola, desarrollar una función que devuelva la cantidad de nodos que tiene.
*/

#include <iostream>
#include <string.h>
using namespace std;

struct Alu {
	int legajo;
	int curso;
	char apellido[50];
};
struct Nodo {
	Alu info;
	Nodo* sig;
};

int devolverCantidadNodos(Nodo* &colaFte, Nodo* &colaFin);
void encolar (Nodo* &colaFte, Nodo* &colaFin, Alu aluAux);
Alu desencolar (Nodo* &colaFte, Nodo* &colaFin);
void mostrar (Nodo* lista);

int main (){
	Nodo* colaFte = NULL;	
	Nodo* colaFin = NULL;
	Alu aluAux;

	int c;
	
	cout<<" Voy a formar la cola, voy a encolar: "<<endl;
	while(1){
		cout<<"Ingrese legajo (salgo con cero): "; cin>>aluAux.legajo; 
		cout<<"Ingrese apellido: ";	 cin>>aluAux.apellido;
		cout<<"Ingrese curso: "; cin>>aluAux.curso;
		if (aluAux.legajo == 0)
			break;
		encolar(colaFte, colaFin, aluAux);
		mostrar(colaFte);
		cout<<endl;
	}

	mostrar(colaFte); cout<<endl;
	c = devolverCantidadNodos(colaFte,colaFin);
	cout<<"Cantidad de nodos: "<<c<<endl;
	mostrar(colaFte);

	return 0;
}
//-------------------------------------------------------
int devolverCantidadNodos(Nodo* &colaFte, Nodo* &colaFin){
	int cant=0;

	//si quiero dejar la cola como estaba:
	Nodo* auxFte = NULL;
	Nodo* auxFin = NULL;

	while(colaFte != NULL){
		encolar(auxFte, auxFin, desencolar(colaFte,colaFin));
		cant++;
	}
	colaFte = auxFte;
	colaFin = auxFin;

	return cant;
}
//-------------------------------------------------------
void encolar (Nodo* &colaFte, Nodo* &colaFin, Alu aluAux){
	Nodo* nuevo = new Nodo();
	nuevo->info = aluAux;
	nuevo->sig = NULL;

	if(colaFte == NULL){
		colaFte = nuevo; 
	}else{
		colaFin->sig = nuevo; 
	}
	colaFin = nuevo;
}
//-----------------------------------------------
Alu desencolar (Nodo* &colaFte, Nodo* &colaFin){
	Alu l = colaFte->info;	
	Nodo* aux = colaFte;
	colaFte = colaFte->sig;
	if(colaFte==NULL)
		colaFin=NULL;
	delete aux;
	return l;
}
//---------------------------------------
void mostrar (Nodo* lista){ 
	while(lista != NULL){
		cout<<lista->info.legajo<<" "<<lista->info.apellido<<" "<<lista->info.curso<<" -> ";
		lista = lista->sig;	
	}
}	