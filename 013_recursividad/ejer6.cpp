/* Sucesion de Fibonacci
ec de recurrencia  Fi
caso base 
*/
#include <iostream>
using namespace std;

int Fibonacci (int );

int main (){
	int numero,resSucesion;
	cout<<"ingrese un numero: ";
	cin>>numero;
	resSucesion=Fibonacci(numero);
	cout<<"la sucesion de Fibonacci es "<<resSucesion<<endl;
	return 0;
}

int Fibonacci (int n){
	int resultado;
//vemos primero el caso base
	if(n==0 || n==1){
		resultado=1;		
	}
	//ecuacion de recurrencia
	else {
		resultado=Fibonacci(n-1)+Fibonacci(n-2);
	
	}
	return resultado;
}