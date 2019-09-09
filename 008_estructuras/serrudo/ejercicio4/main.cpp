#include <iostream>
#include <string> 
using namespace std;
#include "funciones.hpp"

int main (){

	alumnosStruct alum[]={{"pedro",1000,5},
					{"juan",1001,8},
					{"jose",2002,10},
					{"daniel",8080,9},
					{"emiliano",500,2},
					};
	int len = 5, salir=1, newNota,opcion,pos;
	string nombre;
	float prom;
	
	while (salir){
		cout<<"[1]- Buscar alumno."<<endl;
		cout<<"[2]- Modificar nota."<<endl;
		cout<<"[3]- Mostrar promedios."<<endl;
		cout<<"Elegir número de opción (0 para salir): ";
		cin>>opcion;
		cout<<""<<endl;

		switch (opcion){
			case 0: salir=0; break;
			case 1:
				do{
					cout<<"*** Ingresar nombre del alumno: ";
					cin>>nombre;
					pos=buscar(alum,len,nombre);
					if (pos!=-1)
						cout<<alum[pos].nombre<<" || Legajo: "<<alum[pos].legajo<<" || Nota: "<<alum[pos].nota<<endl<<endl;
					else
						cout<<"No se encuentra el nombre"<<endl<<endl;
				}
				while (pos==-1);
				break;
			case 2:
				do{
					cout<<"*** Ingresar nombre del alumno: ";
					cin>>nombre;
					pos=buscar(alum,len,nombre);
					if (pos!=-1){
						cout<<alum[pos].nombre<<" || Legajo: "<<alum[pos].legajo<<" || Nota: "<<alum[pos].nota<<endl;
						cout<<"Ingresar nueva nota: ";
						cin>>newNota;
						modificar(alum,pos,newNota);
					}
					else
						cout<<"No se encuentra el nombre"<<endl<<endl;
				}
				while (pos==-1);
				break;
			case 3:
				prom= promedio(alum,len);
				cout<<"****** Promedio de notas: "<<prom<<endl;

				pos= buscarMejor(alum,len);
				cout<<"****** Mejor nota: ";
				cout<<alum[pos].nombre<<" || Legajo: "<<alum[pos].legajo<<" || Nota: "<<alum[pos].nota<<endl;

				pos= buscarMenor(alum,len);
				cout<<"****** Menor nota: ";
				cout<<alum[pos].nombre<<" || Legajo: "<<alum[pos].legajo<<" || Nota: "<<alum[pos].nota<<endl;
				cout<<""<<endl;
				break;
			default:
				cout<<"Opción inválida."<<endl<<endl;
				break;
		}
	}
	return 0;
}