#include <iostream>
#include <string> 
using namespace std;
#include "funciones.hpp"

int main (){

	stockArticulos stock[CANT];
	int len = 0, pos, ciclo=1,opcion,newPre,newCant;
	string aBuscar;

 	while (ciclo){
 		cout<<"\t\t**** Función ****"<<"\t\t\t[opción]"<<endl;
 		cout<<"\t1- Ingresar nuevo producto "<<"\t\t\t[1]"<<endl;
 		cout<<"\t2- Buscar producto "<<"\t\t\t\t[2]"<<endl;
 		cout<<"\t3- Modificar stock y precio "<<"\t\t\t[3]"<<endl;
 		cout<<"\tEscribir numero de opción (0 para salir):"<<"\t[...] ";
 		cin>>opcion;
 		cout<<"....................................................."<<endl<<endl;
 		
 		switch (opcion){
 			case 0: ciclo=0; break;
 			case 1:	agregar(stock, CANT, len);
 					cout<<""<<endl;
 					break;
 			case 2: do{
 						cout<<"Ingresar nombre del articulo a buscar: ";
 						cin>>aBuscar;
 						pos = buscar(stock,len,aBuscar);
 					}
 					while (pos==-1);
 					cout<<""<<endl;		
					cout<<"\tCódigo: "<<stock[pos].cod<<"\tPrecio: $"<<stock[pos].pre<<"\t Cantidad: "<<stock[pos].cant<<endl<<endl;
					break;
			case 3: do{
 						cout<<"Ingresar nombre del articulo a modificar: ";
 						cin>>aBuscar;
 						pos = buscar(stock,len,aBuscar);
 					}
 					while (pos==-1);
 					cout<<"Ingresar nuevo precio y cantidad: ";
 					cin>>newPre>>newCant;
 					modificar(stock,pos,newPre,newCant);
 					break;
 			default: cout<<"Opción incorrecta."<<endl;
 		}
 	}
 	return 0;
}
