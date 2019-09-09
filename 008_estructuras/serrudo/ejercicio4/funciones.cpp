using namespace std;
#include "funciones.hpp"
#include <iostream>

//****************************************************
//devuelve -1 si no se encuentra.
int buscar(alumnosStruct arr[], int len, string nom){
	int i=0,pos=-1;
	for(i=0;i<len;i++){
		if(arr[i].nombre == nom){
			pos = i;
			break;			
		}
	}
	return pos;
}
//*****************************************************
void modificar(alumnosStruct arr[], int pos, int newNota){
	arr[pos].nota=newNota;
}
//*****************************************************
float promedio(alumnosStruct arr[], int len){
	float promedio;
	float suma = 0;
	for(int i=0;i<len;i++){
		suma += arr[i].nota;
	}
	promedio = suma/ len;
	return promedio;
}
//*****************************************************
int buscarMejor(alumnosStruct arr[], int len){
	float mejor = 0;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].nota > mejor){
			mejor = arr[i].nota;
			pos = i;
		}
	}
	return pos;
}
//******************************************************
int buscarMenor(alumnosStruct arr[], int len){
	float menor = 999999999999999;
	int pos;
	for(int i=0;i<len;i++){
		if(arr[i].nota < menor){
			menor = arr[i].nota;
			pos = i;
		}
	}
	return pos;
}



