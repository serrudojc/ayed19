//Implementacion de una LIFO, STACK o PILA

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* sig;
};

void push (Nodo* &pila, int valor);
int pop (Nodo* &pila);
void mostrar (Nodo* lista);

int main(int argc, char const *argv[])
{
	Nodo* pila = NULL;	//mi pila/lista, apunta a NULL pq no tengoo nada aun
	int dat;

	cout<<" Voy a formar la pila, voy a pushear: "<<endl;
	while(1){
		cout<<"Ingrese dato a pila (salgo con cero): ";
		cin>>dat;
		if (dat == 0)
			break;
		push(pila, dat);
		mostrar(pila);
		cout<<endl;
	}
	cout<<"Ahora voy liberado (popeando): "<<endl;
	while(pila->sig != NULL){
		pop(pila);
		mostrar(pila);
		cout<<endl;
	}
	return 0;
}
//---------------------------------------
//apilo
void push (Nodo* &pila, int valor){
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;
	nuevo->sig = pila;	

	pila = nuevo; 
}
//---------------------------------------
//desapilo
int pop (Nodo* &pila){
	int v = pila->dato;
	Nodo* aux = pila;
	pila = pila->sig;
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