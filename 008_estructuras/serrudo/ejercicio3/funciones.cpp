using namespace std;
#include "funciones.hpp"
#include <iostream>

//****************************************************

void agregar(stockArticulos arr[], int n, int& len){
	
	if (len==n)
		cout<<"Está lleno"<<endl;
	else{
		cout<<"Ingresar CODIGO del articulo: "; //PROBLEMA: si ingreso caracteres, se vuelve loco el programa. Validar.
		cin>>arr[len].cod;

		cout<<"Ingresar NOMBRE del articulo: ";
		cin>>arr[len].nombre;					//Automaticamente le da un largo al string? no tengo que definir, char nombre[30]

		cout<<"Ingresar precio del articulo: ";
		cin>>arr[len].pre;

		cout<<"Ingresar cantidad del articulo: ";
		cin>>arr[len].cant;

		len++;
	}
	return;
}
//****************************************************
//devuelve -1 si no se encuentra.
int buscar(stockArticulos arr[], int len, string nom){
	int i=0,pos=-1;
	for(i=0;i<len;i++){
		if(arr[i].nombre == nom){
			pos = i;
			break;			
		}
	}
	return pos;
}
//****************************************************
void modificar(stockArticulos arr[], int pos, int precio, int cantidad){
	arr[pos].pre=precio;
	arr[pos].cant=cantidad;
}