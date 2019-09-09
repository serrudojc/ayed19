/*	Crear una funcion que reciba dia, mes y año, y devuelva el dia (numerico) de la semana que fue.
Crear un programa ppal que llame a la funcion e imprima el nombre del dia. La formula a usar es (ver fotocopia)*/

#include <iostream>
using namespace std;

int vecRegular[12]={0,3,3,6,1,4,6,2,5,0,3,5};
int vecBisiesto[12]={0,3,4,0,2,5,0,3,6,1,4,6};

int diaDeLaSemana (int dia, int mes, int anio){
	int x;
	if ((anio%400==0 || anio%100!=0) && anio%4==0){
		x=vecBisiesto[mes-1];
	}else{
		x=vecRegular[mes-1];
	}
	int d = ( (anio-1)%7 + ((anio-1)/4 - (3*(anio-1)/100+1)/4)%7 + x + dia%7 )%7;

	return d;

}

int main(){
	int dia, mes,anio, diaSemana;

	cout<<"ingrese un dia"<<endl;
	cin>>dia;
	cout<<"ingrese un mes"<<endl;
	cin>>mes;
	cout<<"ingrese un anio"<<endl;
	cin>>anio;

	diaSemana= diaDeLaSemana(dia,mes,anio);
	switch (diaSemana){
		case 0:
		cout<<"domingo"<<endl;
		break;
		case 1:
		cout<<"lunes"<<endl;
		break;
		case 2:
		cout<<"martes"<<endl;
		break;
		case 3:
		cout<<"miercoles"<<endl;
		break;
		case 4:
		cout<<"jueves"<<endl;
		break;
		case 5:
		cout<<"viernes"<<endl;
		break;
		case 6:
		cout<<"sabad0"<<endl;
		break;
		default:
		cout<<"error"<<endl;
		break;
	}
	return 0;
}