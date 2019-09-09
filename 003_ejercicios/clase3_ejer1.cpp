#include<iostream>
using namespace std;

int i=0, numero=0, mayor=0;
/*ojo!!! ver si funciona mayor=0 para numeros negativos*/
int main (){

	while (i<10){
		cout<<"ingresar diez numeros"<<endl;
		cin>>numero;
		if(numero>mayor)
			mayor=numero;
		i++;
	}
	cout<<"numero mayor es:"<<mayor<<endl;
	return 0;
}
