/* Crear una funcion que reciba un dia, mes y año y devuelva "true" si se trata de una fecha valida y "false" si no lo es.
Recorda que:
a) tienen 31 dias: enero, marzo,mayo,julio,agosto,octubre y diciembre
b) tienen 30 dias: abril, junio, sept y nov
c) tiene 29 dias feb, si es bisiesto. 
d) tiene 28 dias feb, si NO es bisiesto.
nota: son bisiestos, años que son multiplos de 4 y no son multiplos de 100 ó que son multiplos de 400. */

#include <iostream>
using namespace std;

bool validaFecha (int dia, int mes, int anio);
//---------------------------------------------------------
int main (){
	int DD,MM,YYYY;

	cout<<"ingrese dia DD, mes MM y año YYYY: ";
	cin>>DD>>MM>>YYYY;	

	if (validaFecha(DD,MM,YYYY))
		cout<<"Fecha válida."<<endl;
	else
		cout<<"Fecha inválida."<<endl;

	return 0;
}
//---------------------------------------------------------
bool validaFecha (int dia, int mes, int anio){

	if (dia<=0)
		return false;
//se puede hacer de otra forma? seguro, pero lo pensé así. Otro pibe hizo dos vectorBisiesto y vectorNoBisiesto[12]={31,28,31...}
	switch (mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(dia<=31)
					return true;
				break;
		case 4:
		case 6:
		case 9:
		case 11:
				if(dia<=30)
					return true;
				break;
		case 2: 
				//es bisiesto? 
				if ( (anio%4==0 && anio%100!=0) || (anio%400==0)  ){
					if (dia<=28)
						return true;
				}else{
					if (dia<=29)
						return true;
				}
		default: return false; break;
	}
	return false;
}