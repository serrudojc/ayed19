#include<iostream>
using namespace std;

int m,i;

int main (){
	cout<<"ingresar entero"<<endl;
	cin>>m;
	for(i=1;i<m;i++){
		if(i%3==0 && i%5!=0){
			cout<<"multiplos de 3 que no son multiplos de 5:...."<< i<<endl;
		}
	}
	return 0;
}