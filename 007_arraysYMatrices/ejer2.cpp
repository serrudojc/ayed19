/*
Ejercicio Nro. 2:
Dado un conjunto (<=100) de valores enteros de los cuales el último es cero y no
debe procesarse:
• Informar el valor mínimo y su posición dentro del conjunto. Si el mínimo no es
único, informar todas las posiciones donde se encuentre.
• Informar todos los elementos impares que ocupan una posición par.


#include <iostream>
using namespace std;

int main (){
	int n,pos;
	cout<<"Ingrese un N tamaño del vector, menor a 100."<<endl;
	cin>>n;

	while (n>100){
		cout<<"Ingrese un N tamaño del vector, menor a 100."<<endl;
		cin>>n;
	}
	int vec[n];
	agregar (vec,n);
	minimo (vec,n)
}
	
void agregar (arr[],tam){
	cout<<"Ingresar numeros. Terminar con 0"<<endl;
	for (int i=0;i<tam;i++)
		cin>>arr[i];
}

void minimo (){

}
*/

//PROFE**************************************

#include <iostream>
using namespace std;
#define N 10	//defino un valor N como constante. Luego, si quiero que valga 100, como dice el enunciado, sólo la cambio aca.

void inicializar(int arr[],int n);
void agregar (int arr[], int n, int& len, int v);
void mostrar (int arr[],int len);

int main (){
	int vec[N], len=0, n, k=0;

	inicializar (vec,N);
	cout<<"ingresar un numero: ";
	cin>>n;
	while (n!=0 && len<N){		//sale cuando es cero o llené el vector. 
		agregar (vec,N,len,n);
		cout<<"Ingrese otro numero: "; //no me gusta esto. no me deberia pedir el ultimo valor (si lleno el vector). igual, no lo tiene en cuenta.
		cin>>n;
	}
//Esto me muestra mi vector original
	for (int i=0;i<N+2;i++)	//N es el tamaño del vector. +2 es que por las dudas, muestro mas valores. Si todo está bien, en esos valores extra tiene qe mostrar falopa.
		cout<<"muestro vector original vec["<<i<<"] "<<"valor: "<<vec[i]<<endl;

	int vecPosMinimos[len];
	inicializar (vecPosMinimos,len);
	int lenMinimo=0;
	int minimo =  9999999;

	for (int i=0; i<len;i++){
		if (vec[i]<=minimo){
			if(vec[i]==minimo){
				agregar(vecPosMinimos,len,lenMinimo,i);
			}
			else{
				minimo=vec[i];
				inicializar(vecPosMinimos,lenMinimo);
				lenMinimo=0;
				agregar(vecPosMinimos,len,lenMinimo,i);
			}
		}
	}
	cout<<"---------------------------"<<endl;
	cout<<"valor minimo es "<<minimo<<endl;
	mostrar(vecPosMinimos, lenMinimo);

	cout<<"---------------------------"<<endl;
	while (k*2 <= len){
		if(vec[k*2]%2 != 0)
			cout<<"vec["<<k*2<<"] tiene valor impar y es: "<<vec[k*2]<<endl;
		k++;
	}
}
//--------------------------------------------------------------
void inicializar(int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=0;
	return;
}
//--------------------------------------------------------------
void agregar (int arr[], int n, int& len, int v){
	
	if (len == n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}
//--------------------------------------------------------------
void mostrar (int arr[],int len){
	for(int i=0; i<len; i++)
		cout<<"posicion del minimo valor en el vec original: "<<arr[i]<<endl;
	return ;
}
