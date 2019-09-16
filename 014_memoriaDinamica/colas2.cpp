#include <iostream>
#include <string.h>
using namespace std;

struct Nodo {
	Alu info;
	Nodo* sig;
};

struct Alu {
	int legajo;
	int curso;
	char apellido[50];
}

int devolverCantidadNodos(Nodo* colaFte, Nodo* colaFin);
void encolar (Nodo* &colaFte, Nodo* &colaFin, int leg, char ape[], char cur[]);
int desencolar (Nodo* &colaFte, Nodo* &colaFin);
void mostrar (Nodo* lista);

int main (){
	Nodo* colaFte = NULL;	
	Nodo* colaFin = NULL;
	int leg;
	char ape[30], cur[10];
	
	cout<<" Voy a formar la cola, voy a encolar: "<<endl;
	while(1){
		cout<<"Ingrese legajo (salgo con cero): "; cin>>leg; 
		cout<<"Ingrese apellido: "; cin>>ape;
		cout<<"Ingrese curso: "; cin>>cur;
		if (leg == 0)
			break;
		encolar(colaFte, colaFin, leg, ape, cur);
		mostrar(colaFte);
		cout<<endl;
	}

	mostrar(colaFte);

	cout<<"Cantidad de nodos: "<<devolverCantidadNodos(colaFte,colaFin)<<endl;
	mostrar(colaFte);

	return 0;
}
//-------------------------------------------------------
int cantidadDeNodos(Nodo* &colaFte, Nodo* &colaFin){
	int cant=0;

	//si quiero dejar la cola como estaba:
	Nodo* &auxFte = NULL;
	Nodo* &auxFin = NULL;

	while(colaFte != NULL){
		encolar(auxFte, auxFin, desencolar(colaFte,colaFin));
		cant++;
	}
	colaFte = auxFte;
	colaFin = auxFin;

	return cant;
}
//-------------------------------------------------------
void encolar (Nodo* &colaFte, Nodo* &colaFin, int leg, char ape[], char cur[]){
	//aca creamos un nodo, que está contento por ahi, flotanto solo(nadie apunta a él y el apunta a NULL)
	Nodo* nuevo = new Nodo();
	nuevo->legajo = leg;
	strcpy(nuevo->apellido, ape);
	strcpy(nuevo->curso, cur);
	nuevo->sig = NULL;

	//si el valor es nulo, entonces está vacio
	if(colaFte == NULL){
		colaFte = nuevo; //colaFte y ColaFin va apuntar al mismo elemento, caso de vacio
	}else{
		colaFin->sig = nuevo; //
	}
	colaFin = nuevo;
}
//-----------------------------------------------
int desencolar (Nodo* &colaFte, Nodo* &colaFin){
	int l = colaFte->legajo;	//sacamos el primero
	Nodo* aux = colaFte;
	colaFte = colaFte->sig;
	if(colaFte==NULL)
		colaFin=NULL;
	delete aux;
	return l;
}
//---------------------------------------
void mostrar (Nodo* lista){ //puedo pasar por valor, pq no estoy modificando la lista.
//mientras el puntero lista no apunte a NULL
	while(lista != NULL){
		cout<<lista->legajo<<" "<<lista->apellido<<" "<<lista->curso<<" -> ";
		lista = lista->sig;		//hay que avanzar
	}
}	