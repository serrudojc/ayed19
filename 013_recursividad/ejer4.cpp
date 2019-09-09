/* Factorial de Potencia


*/
#include <iostream>
using namespace std;

int sacarPotencia (int b, int e);

int main (){
	int base,exponente,pot;
	cout<<"ingrese base y exponente: ";
	cin>>base;
	cin>>exponente;
	pot=sacarPotencia(base,exponente);
	cout<<"la potencia es "<<pot<<endl;
	return 0;
}

int sacarPotencia (int b, int e){
	int resultado;
//vemos primero el caso base
	if(e==0){
		resultado=1;		
	}
	else{
		resultado=b*sacarPotencia(b,e-1);
	}
	return resultado;
}