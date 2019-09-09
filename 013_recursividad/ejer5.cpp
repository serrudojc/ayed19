/* Factorial de Division Entera
ec de recurrencia  dividendo/divisor = 1+(dividendo-divisor)/divisor
caso base divisor>dividendo = 0
*/
#include <iostream>
using namespace std;

int divEntera (int dividendo, int divisor);

int main (){
	int dividendo,divisor,div;
	cout<<"ingrese dividendo y divisor: ";
	cin>>dividendo;
	cin>>divisor;
	div=divEntera(dividendo,divisor);
	cout<<"la division es "<<div<<endl;
	return 0;
}

int divEntera (int dividendo, int divisor){
	int resultado;
//vemos primero el caso base
	if(divisor>dividendo){
		resultado=0;		
	}
	else if (divisor==dividendo){
		resultado=1;
	}else{
		resultado=1+divEntera(dividendo-divisor,divisor);
	}
	return resultado;
}