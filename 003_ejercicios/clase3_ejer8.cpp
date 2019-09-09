#include <iostream>
using namespace std;

int anio, mes, dia,fecha;
int main(){
	cout<<"Ingresar año AAAA"<<endl;
	cin>>anio;
	anio=anio*10000;
	cout<<"Ingresar mes MM"<<endl;
	cin>>mes;
	mes=mes*100;
	cout<<"Ingresar dia DD"<<endl;
	cin>>dia;
	fecha=anio+mes+dia;
	cout<<"fecha: "<<fecha<<endl;
	return 0;
}
//tengo problema para ver años 1000, para mostrar ceros