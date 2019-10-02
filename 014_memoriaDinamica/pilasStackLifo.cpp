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
//pila es puntero a nodo, como c/vez q inserto un nodo, voy a modificarlo, el pointer se pasa por referencia
void push (Nodo* &pila, int valor){
	/*creo un puntero llamado nuevo, al cual asigno un nuevo espacio en memoria, creo
	un registro en tiempo de ejecucion. La dir de memoria de ese registro se la asigno a nuevo */
	Nodo* nuevo = new Nodo();
	/*Al campo de dato le asigno el valor. el operador de acceso a un miembro de un registro usamos 
	el operador . (punto), pero el operador de acceso a un miembro de un registro apuntado por un 
	puntero es -> */
	nuevo->dato = valor;
	nuevo->sig = pila;	

	pila = nuevo; 
}
//---------------------------------------
//desapilo 
//paso como parametro, el comienzo de la pila
int pop (Nodo* &pila){
	//creamos nodo auxiliar que le asignamos la dir de comienz de la pila
	Nodo* aux = pila;
	//asginamos el campo info del registro apuntado por el puntero aux
	int v = aux->dato;
	//la pila en lugar de apuntar donde apuntaba, ahora apunta al sguiente, pq vamos a borrar el primer nodo
	pila = aux->sig;
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