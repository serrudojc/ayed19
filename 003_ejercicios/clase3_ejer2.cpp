#include<iostream>

using namespace std;

int numero, i, sum=0, k=0;
float prom=0;

int main (){
	for(i=0;i<10;i++){
		cout<<"ingresar numero"<<endl;
		cin>>numero;
		if(numero>100){
			prom=prom+numero;
			k=k+1;
			//ojo, si no ingreso ningun numero mayor a 100, va dividir por cero
		}
		if (numero<-10){
			sum=sum+numero;
		}
	}
	prom=prom/k;
	cout<<"promedio de nros mayores a 100:....."<<prom<<endl;
	cout<<"suma de nros menores a -10:...."<<sum<<endl;
	return 0;
}