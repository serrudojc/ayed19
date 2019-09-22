/*
Ejercicio Nro. 2:
Dada una pila y un valor X, desarrollar un procedimiento que inserte X como tercer
valor de la pila. Retornar un parámetro con valor 'S' o 'N' según haya sido exitoso o no
el requerimiento.
*/
#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* sig;
};

void push (Nodo* &pila, int valor);
int pop (Nodo* &pila);
void mostrar (Nodo* lista);
char insertarValorEnPila (Nodo* &pila, int x);

int main(int argc, char const *argv[]){
	int opcion, valor, posicion;
	Nodo* pila = NULL;	//mi pila/lista, apunta a NULL pq no tengoo nada aun

	do{
		cout<<"\t1-Push."<<endl;
		cout<<"\t2-Pop."<<endl;
		cout<<"\t3-Mostrar Pila."<<endl;
		cout<<"\t4-Ejercicio 2."<<endl;
		cout<<"\t5-."<<endl;
		cout<<"\t6-."<<endl;
		cout<<"\t7-."<<endl;
		cout<<"\tIngresar Opción: ";
		cin>>opcion;
		cout<<endl;

		switch (opcion){
			case 1:
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
				break;
			case 2:
				cout<<"Funcion de popear.: ";
				cout<<"Ahora voy liberado (popeando): "<<endl;
				while(pila->sig != NULL){
					pop(pila);
					mostrar(pila);
					cout<<endl;
				}
				cout<<endl<<endl;
				break;	
			case 3: 
				mostrar(pila); cout<<endl;
				break;
			case 4:
				cout<<"ingresar valor: ";
				cin>>valor;
				insertarValorEnPila(pila, valor);
				break;
				
			default:
				cout<<"opcion incorrecta."<<endl<<endl;	
		}
	}
	while(opcion);

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
//---------------------------------------------
char insertarValorEnPila (Nodo* &pila, int x){
	//declaro pila auxiliar
	Nodo* pilaAux = NULL;
	int contador = 0;
	char resultado;

	while (pila != NULL){
		push (pilaAux, pop(pila));
		contador++;
	}
	if (contador >= 2){
		resultado = 'S';
/*
		for (int i=0; i<2; i++){
			push(pila,pop(pilaAux));
		}
*/
		push (pila, pop(pilaAux));
		push (pila, pop(pilaAux));
		push (pila, x);
		while(pilaAux != NULL){
			push (pila, pop(pilaAux));
		}
	}else{
		resultado = 'N';
	}
	return resultado;
}
//revisar: si vuelvo a realizar la operacion, no me cuenta el primer elemento
//--------------------------------------------------------