//Implementacion de una FIFO, COlA o QUEUE

#include <iostream>
using namespace std;


struct Nodo {
	int dato;
	Nodo* sig;
};

void encolar (Nodo* &colaFte, Nodo* &colaFin, int v);
int desencolar (Nodo* &colaFte, Nodo* &colaFin);
void mostrar (Nodo* lista);

int main(int argc, char const *argv[])
{
	Nodo* colaFte = NULL;	//mi pila/lista, apunta a NULL pq no tengoo nada aun
	Nodo* colaFin = NULL;
	int dat;

	cout<<" Voy a formar la cola, voy a encolar: "<<endl;
	while(1){
		cout<<"Ingrese dato a la cola (salgo con cero): "; 
		cin>>dat;
		if (dat == 0)
			break;
		encolar(colaFte, colaFin, dat);
		mostrar(colaFte);
		cout<<endl;
	}

	cout<<"Ahora voy liberado (popeando o desencolando): "<<endl;
	while(colaFte->sig != NULL){
		desencolar(colaFte, colaFin);
		mostrar(colaFte);
		cout<<endl;
	}


	return 0;
}
//---------------------------------------
//apilo

void encolar (Nodo* &colaFte, Nodo* &colaFin, int v){
	//aca creamos un nodo, que está contento por ahi, flotanto solo(nadie apunta a él y el apunta a NULL)
	Nodo* nuevo = new Nodo();
	nuevo->dato = v;
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
	int v = colaFte->dato;	//sacamos el primero
	Nodo* aux = colaFte;
	colaFte = colaFte->sig;
	if(colaFte==NULL)
		colaFin=NULL;
	delete aux;
	return v;
}
//---------------------------------------
void mostrar (Nodo* lista){ //puedo pasar por valor, pq no estoy modificando la lista.

//mientras el puntero lista no apunte a NULL
	while(lista != NULL){
		cout<<lista->dato<<" -> ";
		lista = lista->sig;		//hay que avanzar
	}
}	