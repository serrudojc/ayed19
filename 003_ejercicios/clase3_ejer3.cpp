#include<iostream>

using namespace std;

int i, numero=1, may=0, posMax=0;

int main (){
	while(numero>=0){
		cout<<"ingrese numero:"<<endl;
		cin>>numero;
		i=i+1;
		if(numero>may){
			may=numero;
			posMax=i;
		}
	}
	cout<<"valor de numero"<<numero<<endl;
	cout<<"mayor numero es:...."<<may<<"   su posicion fue:..."<<posMax<<endl;
	return 0;
}