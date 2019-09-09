#include <iostream>
#include <string>
using namespace std;

long unificarFecha (int dia, int mes, int anio);

int main (){
	int DD,MM,YYYY;
	long f;

	cout<<"Ingresar dia DD:"<<endl;
	cin>>DD;
	cout<<"Ingresar mes MM:"<<endl;
	cin>>MM;
	cout<<"Ingresar año YYYY:"<<endl;
	cin>>YYYY;

	f=unificarFecha (DD, MM, YYYY);
	cout<<"Fecha unificada YYYYMMDD:"<<f<<endl;
	return 0;
}

long unificarFecha (int dia, int mes, int anio){
	long fecha;

	fecha =anio*10000+mes*100+dia;
	return fecha;
}

//como hago para ver 0525, cero delante.