

/*
Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en la pila. Si se ingresa un asterisco se saca un
elemento de la pila. Imprimir la secuencia de caracteres que se sacaron de la
pila. 
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/

#include <iostream>
using namespace std;

int main (){
	struct Nodo{
		char info;
		Nodo *sig;
	};

	char caracter;
	Nodo *pila = NULL;

	do
	{
		cout<<"Ingresar caracter: ";
		cin>>caracter;

		if()
	} while (caracter != '0');
	

	return 0;
}