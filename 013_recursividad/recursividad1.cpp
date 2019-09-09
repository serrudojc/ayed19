#include <iostream>
using namespace std;

int calculaFactorial (int n);
int main(int argc, char const *argv[])
{
	int num,fac;

	cout<<"ingresar numero: ";
	cin>>num;
	fac=calculaFactorial(num);
	cout<<"factorial es "<<fac<<endl;
	return 0;
}
int calculaFactorial (int n){
	if (n==0)
		return 1;
	else{
		return n*calculaFactorial(n-1);
	}
}