#include <iostream>
#include "matrices.hpp"
using namespace std;

void inicializar (float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			m[i][j] = 0;
		}
	}
	return;
}

void cargar (float m[][MAX_COLUMNAS], int f, int c){
	float medicion;
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << "Ingresar Medicion" << endl;
			cin >> medicion;
			m[i][j] = medicion;
		}
	}
	return;
}

void mostrar(float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

float buscarMaximaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){

	float max=m[0][0];
	posF=0;
	posC=0;
	
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			if(max<m[i][j]){
				max=m[i][j];
				posF=i;
				posC=j;
			}
		}
	}

	return max;	
}

float buscarMinimaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){
	
	float min=m[0][0];
	posF=0;
	posC=0;

	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			if(min>m[i][j]){
				min=m[i][j];
				posF=i;
				posC=j;
			}
		}
	}
	return min;
}

void mostrarResultado(string texto, float valor, int posF, int posC){
	cout<< texto<<valor<< " se encuentra en posicion ["<<posF<<"]["<<posC<<"]"<<endl;

	return;
}