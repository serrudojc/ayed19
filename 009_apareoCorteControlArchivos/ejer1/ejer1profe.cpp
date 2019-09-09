/*
Ejercicio Nro. 1:
Ingresar por teclado dos vectores ordenados que tendrán como máximo 5 elementos cada uno. 
Generar un nuevo vector con el apareo de ambos vectores y mostrarlo por pantalla.
*/
#include <iostream>
using namespace std;

void inicializarVector(int arr[],int n);
void agregar (int arr[], int& len, int n, int v);
//------------------------------------------------------------
int main (){

	int vecA[5], vecB[5],vecC[10];
	int lenA=0,lenB=0,lenC=0;
	int posA=0,posB=0,posC=0; //no usamos si usamos AGREGAR, pero si mas adelante (menos posC)
	int num;

	inicializarVector (vecA,5);
	inicializarVector (vecB,5);
	inicializarVector (vecC,10);

	cout<<"Ingresar valor para el vector A"<<endl; cin>>num;
	while(num>0){
		agregar(vecA,lenA,5,num);
		cout<<"Ingresar valor para el vector A"<<endl; cin>>num;
	}

	cout<<"Ingresar valor para el vector B"<<endl; cin>>num;
	while(num>0){
		agregar(vecB,lenB,5,num);
		cout<<"Ingresar valor para el vector B"<<endl; cin>>num;
	}
	//APAREO
	while(posA<lenA && posB<lenB){
		if(vecA[posA]<vecB[posB]){
			agregar(vecC,lenC,10,vecA[posA]);
			posA++;
		} else{
			agregar(vecC,lenC,10,vecB[posB]);
			posB++;
		}
	}
	while(posA<lenA){
		agregar(vecC,lenC,10,vecA[posA]);
		posA++;
	}
	while(posB<lenB){
		agregar(vecC,lenC,10,vecB[posB]);
		posB++;
	}
//imprimo vectores luego de apareo
	for (int i=0;i<lenA;i++){
		cout<<vecA[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<lenB;i++){
		cout<<vecB[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<lenC;i++){
		cout<<vecC[i]<<" ";
	}
	cout<<endl;
} 
//-------------------------------------------------------
void agregar (int arr[], int& len, int n, int v){
	if (len==n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}
//-------------------------------------------------------
void inicializarVector(int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=0;
	return;
}
