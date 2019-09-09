using namespace std;
#include "vectores.hpp"
#include <iostream>


int buscarMinimo(paisVelocidad arr[], int len){
	float minimo = 999999999999999;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].velMinima < minimo){
			minimo = arr[i].velMinima;
			pos = i;
		}
	}
	return pos;
}

int buscarMaximo(paisVelocidad arr[], int len){
	float maximo = 0;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].velMaxima > maximo){
			maximo = arr[i].velMaxima;
			pos = i;
		}
	}
	return pos;
}

float promedioVelocidadesMaximas(paisVelocidad arr[], int len){
	float promedio;
	float suma = 0;
	for(int i=0;i<len;i++){
		suma += arr[i].velMaxima;
	}
	promedio = suma/ len;
	return promedio;
}

