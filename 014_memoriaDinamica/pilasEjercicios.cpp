//Ejercicio 2: Dada una pila y un valor X, hacer un procedimiento que elimine los 
//2 primeros nodos de la pila y deje el valor X como primero

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
void insertarEnPosicion (Nodo* &pila, int valX, int posY);

int main(int argc, char const *argv[]){
	int opcion, valor, posicion, valorX, posicionY;
	Nodo* pila = NULL;	//mi pila/lista, apunta a NULL pq no tengoo nada aun

	do{
		cout<<"\t1-Ejercicio 1."<<endl;
		cout<<"\t2-Ejercicio 2."<<endl;
		cout<<"\t3-Ejercicio 3."<<endl;
		cout<<"\t4-Ejercicio 4."<<endl;
		cout<<"\t5-Ejercicio 5."<<endl;
		cout<<"\t6-Ejercicio 6."<<endl;
		cout<<"\t7-Ejercicio 7."<<endl;
		cout<<"\t--------------"<<endl;
		cout<<"\t8-Push."<<endl;
		cout<<"\t9-Pop."<<endl;
		cout<<"\t10-Mostrar Pila."<<endl;
		cout<<"\tIngresar Opción: ";
		cin>>opcion;
		cout<<endl;

		switch (opcion){
			
			case 2:
				cout<<"ingresar valor: ";
				cin>>valor;
				cout<<"Fue exitoso?: "<<insertarValorEnPila(pila, valor)<<endl;
				break;
				
			 case 3:
			 	cout<<"Ingresar valor X y posicion Y: ";
			 	cin>>valorX>>posicionY;
			 	insertarEnPosicion(pila, valorX, posicionY);
				break;

			case 8:
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

			case 9:
				cout<<"Funcion de popear.: ";
				cout<<"Ahora voy liberado (popeando): "<<endl;
				while(pila->sig != NULL){
					pop(pila);
					mostrar(pila);
					cout<<endl;
				}
				cout<<endl<<endl;
				break;	

			case 10: 
				mostrar(pila); cout<<endl;
				break;

			default:
				cout<<"opcion incorrecta."<<endl<<endl;	
				break;
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
void mostrar (Nodo* lista){ 
	while(lista != NULL){
		cout<<lista->dato<<" -> ";
		lista = lista->sig;		
	}
}	
//---------------------------------------------
//ejercicio 2
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
//Ejercicio 3
void insertarEnPosicion (Nodo* &pila, int valX, int posY){
	Nodo* pilaAux = NULL;
	int contador = 0;

	//paso a la pila auxiliar
	while(pila != NULL){
		push (pilaAux, pop(pila));
		contador++;
	}
	//chequeo si existe la posicion
	// la posicion la tomamos que empieza de 1
	if (contador >= posY){
		//paso todos hasta la posicion que tengo que insertar
		for(int i=0; i<posY; i++){
			push (pila, pop(pilaAux));
		}
		push(pila, valX);
		//hago while con los push que queden
		while(pilaAux != NULL){
			push(pila, pop(pilaAux));
		}
	}else{
		cout<<"No se puede Insertar"<<endl;
		//si entro por el else, pila va apuntar a NULL. pq hice pop de todo, no punta a nada
		//tengo que volver a pasar todos los valores
		while( pilaAux != NULL){
			push(pila, pop(pilaAux));
		}
	}	
}