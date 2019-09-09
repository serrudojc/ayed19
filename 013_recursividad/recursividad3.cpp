#include <iostream>
using namespace std;

int divisionNatural (int divid, int divis);
int main(int argc, char const *argv[])
{
	int divid, divis, res;

	cout<<"ingresar dividendo y divisor: ";
	cin>>divid>>divis;
	cout<<"division natural es "<<divisionNatural(divid,divis)<<endl;
	return 0;
}
int divisionNatural (int divid, int divis){
	if (divis>divid)
		return 0;
	else if(divid==divis)
		return 1;
	else
		return (1 + divisionNatural(divid-divis,divis));
	
}