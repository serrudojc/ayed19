#include <iostream>
using namespace std;

bool esPrimo (int n);

int main (){
	int num;

	cout<<"ingresar número:"<<endl;
	cin>>num;
	cout<<"Es primo?: ";

	if (esPrimo(num))
		cout<<"Si, es primo."<<endl;
	else
		cout<<"No, no es primo."<<endl;
	return 0;
}

bool esPrimo (int n){
	int i, cont=0;

	for(i=1;i<=n;i++){
		if(n%i==0){
			cont=cont+1;
			if (cont>2)
				return false;
		}
	}
	if(cont==2)
		return true;
	else 
		return false;
}