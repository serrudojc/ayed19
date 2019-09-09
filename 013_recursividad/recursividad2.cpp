#include <iostream>
using namespace std;

int calculaPotencia (int b, int e);
int main(int argc, char const *argv[])
{
	int base, exp, pot;

	cout<<"ingresar base y exponente: ";
	cin>>base>>exp;
	pot=calculaPotencia(base,exp);
	cout<<"potencia es "<<pot<<endl;
	return 0;
}
int calculaPotencia (int b, int e){
	if (e==0)
		return 1;
	else{
		return b*calculaPotencia(b,e-1);
	}
}