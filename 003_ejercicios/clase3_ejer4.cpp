#include<iostream>

using namespace std;

int k, codEq, resultado,i, l;
char codRes;

int main (){
	cout<<"ingrese cantidad de equipos: "<<endl;
	cin>>k;
	for (i=0;i<k;i++){
		cout<<"ingresar cod equipo: "<<endl;
		cin>>codEq;
		for(l=0;l<k-1;l++){
			cout<<"ingresar cod de resultado (G, E, P): "<<endl;
			cin>>codRes;
			switch(codRes){
				case 'G': resultado=resultado+3; break;
				case 'E': resultado=resultado+1; break;
				case 'P': resultado=resultado+0; break;
				default: 
					cout<<"código incorrecto"<<endl;
					k=k-1;
			}
		}
		cout<<"resultado total: "<<resultado<<endl;
	}	
}