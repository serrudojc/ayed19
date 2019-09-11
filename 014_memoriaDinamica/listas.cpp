// Programa Principal
#include <iostream>
#include <stdlib.h>

using namespace std;

//nodo generico
struct Nodo{
	int info;
	Nodo *sig;	
};
//declaro la lista (el puntero al primer nodo)
Nodo *lista = NULL;
// lista->NULL lista apunta a null


Nodo *temporario = NULL;

void agregarNodo(Nodo*& lista, int num);
void mostrar (Nodo* lista);
void liberar (Nodo*& lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int x);
int eliminarPrimerNodo (Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, int x);
void ordenar(Nodo*& lista);
Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc);

int main (){
	int opcion, valor;
	bool enc;
	do{
		cout<<"\t1-Agregar nodo."<<endl;
		cout<<"\t2-Mostrar."<<endl;
		cout<<"\t3-Liberar."<<endl;
		cout<<"\t4-Buscar."<<endl;
		cout<<"\t5-Eliminar."<<endl;
		cout<<"\t6-Eliminar Primer Nodo."<<endl;
		cout<<"\t7-Insertar ordenado.(LISTA DEBE ESTAR ORDENADA o VACIA)"<<endl;
		cout<<"\t8-Ordenar."<<endl;
		cout<<"\t9-Buscar e Insertar Ordenado."<<endl;
		cout<<"\t0-Salir."<<endl;
		cout<<"\tIngresar Opción: ";
		cin>>opcion;
		cout<<endl;

		switch (opcion){
			case 1:
				cout<<"Ingrese valor agregar: " ;
				cin>>valor;
				agregarNodo(lista,valor);
				cout<<"Elemento agregado."<<endl<<endl;
				break;
			case 2:
				mostrar(lista);	
				cout<<endl<<endl;
				break;	
			case 3:
				liberar(lista);
				cout<<"Memoria liberada."<<endl<<endl;
				break;
			case 4:
				//ERROR, al buscar elemento que no existe en la lista
				cout<<"Ingrese valor buscar: ";
				cin>>valor; cout<<endl;
				temporario = buscar(lista,valor);
				if (temporario == NULL)	//sacar el temporario->sig
					cout<<"Valor no encontrado."<<endl<<endl;
				else
					cout<<"Posicion de memoria del valor: "<<temporario<<endl<<endl;
				break;
			case 5:
				//ERROR, al eliminar elemento que no existe en la lista
				cout<<"Ingrese valor a eliminar: ";
				cin>>valor;
				eliminar(lista,valor);				
				break;
			case 6:
				valor = eliminarPrimerNodo(lista);
				cout<<"Primer nodo eliminado y su valor era: "<<valor<<endl;
				break;
			case 7:
				cout<<"Ingrese valor a insertarOrdenado: ";
				cin>>valor;
				insertarOrdenado(lista,valor);
				break;
			case 8: 
				ordenar(lista);
				break;
			case 9: 
				//ERROR al usar la funcion buscar elemento que no existe
				cout<<"Ingrese valor insertar: ";
				cin>>valor;
				temporario = buscaEInsertaOrdenado(lista,valor,enc);
				break;				
			default:
				cout<<"opcion incorrecta."<<endl<<endl;	
		}
	}
	while(opcion);

	return 0;
}
//--------------------------------------------------------------
//Agrego nuevo nodo con valor "num" al final de la lista referenciada por "lista"
void agregarNodo(Nodo*& lista, int num){ // paso lista por referencia
	
	//asigno memoria
	Nodo* p = new Nodo(); 
	p->info = num;
	p->sig = NULL;

	//hay dos casos a comparar, si hay algo o nada
	if(lista==NULL){	//está vacia
		lista = p;
	} else {		//ya hay elementos
		//declaro un aux para no perder la referencia de lista
		//lista y aux van a ser dos punteros que apuntan al primer nodo
		Nodo* aux = lista;
		//si no es el ultimo nodo, entro al while. voy recorriendo toda a lista hasta llegar al ultimo nodo
		while(aux->sig != NULL){
			aux= aux->sig;
		}
	aux->sig = p;
	//delete aux;		//CONSULTA 1: hace falta borrar?(es variable local). qu estaria borrando? cuando asigné memoria a aux?
	}
}
//----------------------------------------------------------
//recorro la lista "lista" y muestro por pantalla el valor de cada nodo
void mostrar (Nodo* lista){ //puedo pasar por valor, pq no estoy modificando la lista.

//mientras el puntero lista no apunte a NULL
	while(lista != NULL){
		cout<<lista->info<<" -> ";
		lista = lista->sig;		//hay que avanzar
	}
}	
/*
	Nodo* aux = lista;
	while(aux != NULL){
		cout<<aux->info<<" -> ";
		aux = aux->sig;
	}
}*/
//------------------------------------------------------------
//recorro la lista "lista" liberando la memoria que ocupan c/u de sus nodos
void liberar (Nodo*& lista){	//recibe por referencia pq voy a modificar la lista
	Nodo* aux;
	while(lista!=NULL){
		aux = lista;	//asignamos la lista, para eliminar el primer nodo
		lista = lista->sig;	//antes de borrar, guardo para no perder la referencia, MUY IMPORTANTE!!!
		delete aux;	//borro lo que apunta aux en ese momento.
	}
}
//---------------------------------------------------------------
//retorna un puntero al nodo que contiene el valor o NULL si no existe
Nodo* buscar(Nodo* lista, int v){	//retorno un puntero del tipo Nodo

	cout<<"Antes WHILE "<<"\t\t\tlista= "<<lista<<"\tlista->info= "<<lista->info<<"\tlista->sig= "<<lista->sig<<endl;

	while((lista->info != v) && (lista != NULL)){	//dos condiciones
		cout<<"Dentro WHILE (antes sig)"<<"\tlista= "<<lista<<"\tlista->info= "<<lista->info<<"\tlista->sig= "<<lista->sig<<endl;
		
		lista = lista->sig;
		cout<<"Dentro WHILE (dspues sig)"<<"\tlista= "<<lista<<"\tlista->info= "<<lista->info<<"\tlista->sig= "<<lista->sig<<endl<<endl;
	}
	cout<<"sali del while"<<endl;
	return lista;
}
//Me tira error cuando asigno lista = lista->sig y esta ultima apunta a NULL
//------------------------------------------------------------------
Nodo* buscar(Nodo* lista, int v){	//retorno un puntero del tipo Nodo

	while((lista->info != v) && (lista != NULL)){	//dos condiciones
		lista = lista->sig;
	}
	return lista;
}


//---------------------------------------------------------------
void eliminar(Nodo*& lista, int x){	//
	Nodo* aux = lista;	//voy a recorrer y no quiero perderlo, guardo el primero. Si uso lista directamente, pierdo la referencia
	Nodo* ant = NULL;	//no hay nada

	while(aux->info != x && aux!=NULL){
		ant = aux;
		aux = aux->sig;	// si salgo del while significa que lo encontré
	}	//tengo que preveer 3 condiciones border; elimino el primero, el ultimo ò alguno del medio
	if(ant!=NULL){
		ant->sig = aux->sig; // sirve para alguno del medio o el ultimo. pero no si es el primero.
	}else{
		lista = aux->sig;	//en vez de borrarlo, es como que lo piso
	}
	delete aux;
}

//---------------------------------------------------------------
int eliminarPrimerNodo (Nodo*& lista){
	Nodo* aux = lista; 	//como es por referencia
	int valor=-1;
	if(aux!=NULL){	//chequeo que no sea una lista vacia
		valor = lista->info;
		lista = lista->sig;
		delete aux;
	}
	return valor;	//si la lista esta vacia, devuelvo -1, sino, devuelvo el valor del primer nodo
}
//---------------------------------------------------------------
//se presume que la lista está ordenada o vacia
//Retorna la direccion de mem del nodo insertado

Nodo* insertarOrdenado(Nodo*& lista, int x){	//recibe la lista y el valor
	//1- tengo que crear el nuevo nodo y asignar memoria
	Nodo* p = new Nodo();
	//2- asignamos el dato al campo dato del nuevo nodo.
	p->info = x;
	p->sig = NULL;
	//terminé de preparar mi nodo aislado
	//Ahora puede pasar que esté al ppio, en el medio ó al final
	//3-creamos nodos auxiliares
	Nodo* aux = lista;
	Nodo* ant = NULL;
	//4- empezamos a iterar, una condicion es que nose termine, la otra, mientras que "sea menor al valor"
	while(aux!=NULL && aux->info <x){ //si tengo q insertar en medio o al final
		ant = aux;
		aux = aux->sig;
	}
	if(lista==NULL){	//primer caso, lista vacia, no entró al while
		lista = p;
	}else if(ant==NULL){
		p->sig = lista;
		lista = p;
	}else{
		ant->sig = p;
		p->sig = aux;
	}
	return p;
}

/*
Basicamente son 4 pasos:
1- Crear un nuevo nodo. Creamos una posicion en memoria para almacenar los elementos a agregar a la lista
2- Asignar a nuevo_nodo->dato el elemento que queremos incluir en la lista.
3- Crear dos nodos auxiliares y asignar lista al primero de ellos.
4- Insertar el elemento a la lista
*/
//---------------------------------------------------------------

void ordenar(Nodo*& lista){	//& por referencia cuando voy a modificar

	Nodo* listAux = NULL;
	while (lista != NULL);
	int valor;
	while(lista != NULL){
		valor = eliminarPrimerNodo(lista);
		insertarOrdenado(listAux,valor);
	}
	lista = listAux;	//pq cuando salgo del while, lista apuntaba a NULL
}
//----------------------------------------------------------------
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc){
	//primero tenemos que saber si está o no está: buscamos
	Nodo* buscado = buscar(lista,v);
	if (buscado != NULL){
		enc = true;
	}else{
		enc = false;
		buscado = insertarOrdenado(lista,v);
	}
	return buscado;
}
