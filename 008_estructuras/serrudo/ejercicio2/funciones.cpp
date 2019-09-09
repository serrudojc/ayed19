using namespace std;
#include "funciones.hpp"
#include <iostream>


int buscarMinimo(notasDatos arr[], int len){
	float minimo = 999999999999999;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].inscriptos < minimo){
			minimo = arr[i].inscriptos;
			pos = i;
		}
	}
	return pos;
}

int buscarMaximo(notasDatos arr[], int len){
	float maximo = 0;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].inscriptos > maximo){
			maximo = arr[i].inscriptos;
			pos = i;
		}
	}
	return pos;
}

float promedio(notasDatos arr[], int len){
	float promedio;
	float suma = 0;
	for(int i=0;i<len;i++){
		suma += arr[i].inscriptos;
	}
	promedio = suma/ len;
	return promedio;
}