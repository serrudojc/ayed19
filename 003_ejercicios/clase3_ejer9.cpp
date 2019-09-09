#include <iostream>
using namespace std;

int fecha, anio,mes,aux,dia,fecha2,anio2,mes2,aux2,dia2;

int main(){
	cout<<"Ingresar fecha 1 en formato YYYYMMDD"<<endl;
	cin>>fecha;
	cout<<"Ingresar fecha 2 en formato YYYYMMDD"<<endl;
	cin>>fecha2;

	//saco fecha dividiendo por 10000
	anio=fecha/10000;
	anio2=fecha2/10000;

	//saco mes restando a fecha el año*10000 y dividiendo por 100
	aux=(fecha-anio*10000);
	mes=aux/100;
	aux2=(fecha2-anio2*10000);
	mes2=aux2/100;
	
	//saco dia
	dia=(fecha-anio*10000-mes*100);
	dia2=(fecha2-anio2*10000-mes2*100);
	
	if(anio2>anio)
		cout<<"fecha mas reciente es: "<<fecha2<<endl;
	else{
		if(anio2<anio)
			cout<<"fecha mas reciente es: "<<fecha<<endl;
		else{
			if(mes2>mes)
				cout<<"fecha mas reciente es: "<<fecha2<<endl;
			else{
				if(mes2<mes)
					cout<<"fecha mas reciente es: "<<fecha<<endl;
				else{
					if(dia2>dia)
						cout<<"fecha mas reciente es: "<<fecha2<<endl;
					else{
						if(dia2<dia)
							cout<<"fecha mas reciente es: "<<fecha<<endl;
						else
							cout<<"ambas fechas son iguales"<<endl;
					}
				}
			}
		}
	}
	return 0;
}