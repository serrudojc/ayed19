#include <iostream>
using namespace std;

bool esMultiplo (int a, int b);

int main (){
	int aa,bb;
	//bool resultado;

	cout<<"ingresar dos números:"<<endl;
	cin>>aa>>bb;
	cout<<"Es múltiplo?: ";

	if (esMultiplo(aa,bb))
		cout<<"Si, es múltiplo."<<endl;
	else
		cout<<"No, no es múltiplo."<<endl;
	return 0;
}

bool esMultiplo (int a, int b){
	
	if(a%b==0)
		return true;
	else
		return false;
}