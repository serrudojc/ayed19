#include<stdlib.h> //para el modulo absoluto

//1-Como hicimos en el otro final + mas unas cosas que veremos mas adelante

struct infoPiso{
	int piso;
	int suben; //personas que suben (deberia ser positivo siempre?)
	int bajan; //personas que bajan
}

//declaramos el nodo
struct Nodo{
	infoPiso info;
	Nodo* arriba;
	Nodo* abajo;
}

//struct para pisos eliminados
struct eliminados{
	int piso;
	int dif;
}

//-----------------------------------------------------------------------------------
// Punto 2
int eliminarLosPisosPrimosArribaDe(Nodo* unPisoActual, FILE* unFlujoDeEscritura);

//-----------------------------------------------------------------------------------
//Punto 3
bool esPrimo(int numero){
	//punto de corte
	bool primo = true;
	numero = abs(numero);

	for(int i=3; i<numero; i++){
		if(numero%i == 0){
			primo = false;
			break;
		}
	}
	return primo;
}
//-----------------------------------------------------------------------------------
//Punto 4. Ver grafico en carpeta.

void eliminarPiso(Nodo* &unPiso){
	//chequeo con dos if, si tengo piso arriba y abajo
	if(unPiso->arriba != NULL)
		unPiso->arriba->abajo = unPiso->abajo;
	else if(unPiso->abajo != NULL)	//caso de que esté en el ultimo piso
		unPiso->abajo->arriba = NULL;
	
	if(unPiso->abajo != NULL)
		unPiso->abajo->arriba = unPiso->arriba;
	else if(unPiso->arriba != NULL)
		unPiso->arriba->abajo = NULL;
	//ahora elimino el piso
	delete(unPiso);
}
//------------------------------------------------------------------------------------
//Punto 5
int eliminarLosPisosPrimosArribaDe(Nodo* unPisoActual, FILE* unFlujoDeEscritura){
	Nodo* aux = unPisoActual->arriba;
	int cantPisosEliminado = 0;
	eliminados reg;
	Nodo* aux2 ; //pq si avanzo con el aux normal, avanzo mal pq ya avancé uno

	while(aux != NULL){
		aux2 = aux;	
		aux = aux->arriba;	//guardo para poder avanzar en el while la proxima vez
		if(esPrimo(aux2->info.piso)){
			reg.piso = aux2->info.piso;
			reg.dif = aux2->info.suben - aux2->info.bajan;
			fwrite(&reg, sizeof(eliminados), 1, unFlujoDeEscritura);

			eliminarPiso(aux2)
			cantPisosEliminado++;
		}
		aux = aux->arriba;
	}
	//
	return cantPisosEliminado;
}
