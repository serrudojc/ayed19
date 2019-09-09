#include <iostream>
using namespace std;

int fecha, anio,mes,fecha2,dia;

int main(){
	cout<<"Ingresar fecha en formato YYYYMMDD"<<endl;
	cin>>fecha;

	//saco fecha dividiendo por 10000
	anio=fecha/10000;

	//saco mes restando a fecha el año*10000 y dividiendo por 100
	fecha2=(fecha-anio*10000);
	mes=fecha2/100;
	
	//saco dia
	dia=(fecha-anio*10000-mes*100);
	
	cout<<"año: "<<anio<<", mes: "<<mes<<", dia: "<<dia<<endl;
	return 0;
}