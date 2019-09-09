/*Recursividad; 
Proceso mediante el cual una funcion se llama a si misma de forma 
repetida (se autoinvoca), hasta que se satisface una determinada condicion 
(caso base) que evita caer en un bucle infinito
*/
#include <iostream>
using namespace std;

int sacarFactorial (int n);

int main (){
	int num,factorial;
	cout<<"ingrese numero: ";
	cin>>num;
	factorial=sacarFactorial(num);
	cout<<"el factorial del numero "<<num<<" es "<<factorial<<endl;

	return 0;
}

int sacarFactorial (int n){
	int factorial;

	if(n==0){
		factorial=1;		
	}
	else{
		factorial=n*sacarFactorial(n-1);
	}
	return factorial;
}


/*prueba escritorio 3!

if(3==0) --->   3*sacarFactorial(2);
if(2==0) ---> 	2*sacarFactorial(1);
if(1==0) ---> 	1*sacarFactorial(0);
if(0==0) --->   1
 */