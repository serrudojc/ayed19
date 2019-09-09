# include <iostream>
using namespace std;

float calcularPorcentajeDiferencia (float a, float b);

int main(){
	long x,y;
	float division2;
	float division,dividendo=47, divisor=5; 
	
	division=dividendo/divisor;
	division2=47/5; /*me muestra decimales?*/
	cout<<"Ingresar dos valores:"<<endl;
	cin>>x>>y;
	while((x+y)==0){
		cout<<"Ingresar dos valores:"<<endl;
		cin>>x>>y;
	}
	cout<<"-------------------------"<<endl;
	cout<<"Porcentaje diferencia es:"<<calcularPorcentajeDiferencia(x,y)<<endl;
	cout<<"prueba de valor con decimales: "<<division<<endl;
	cout<<"prueba 2 de valor con decimales: "<<division2<<endl;
	return 0;
}

float calcularPorcentajeDiferencia (float a, float b){
	return (b-a)*100/(a+b);
}

/*decimales en c++??--> ojo,
 con los valores, solo me toma con comas cuando asigno variables diferenrtes*/

/* ojo, si a+b=0, el programa tira error por division por cero*/