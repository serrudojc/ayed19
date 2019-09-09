/*Ejemplo de clase 5/6/19

Los datos deben estar AGRUPADOS.
Nos sirve para sacar resultados totales y por grupos de claves.

ejemplo:
Cual es el promeedio de todo el curso?
cual es el promedio de cada estudiante?
quien tiene el promedio mas alto?
--------------------------------------------------------------------------
CORTE DE CONTROL GENERICO

inicializar variables globales
	while(pos<len){
		claveAnterior = claveActual;
		Inicializar variables de grupo;

		while (clave anterior == clave actual  &&  pos<len){
			procesar grupo 
			pos++
		}
		imprimir resultados de grupo;
	}
	imprimir resultados globales
--------------------------------------------------------------------------
*/

# include <iostream>
using namespace std;

struct Estudiante{
	int leg;
	char materia[50];
	int nota;
};
Estudiante vecK1053[50]={{2222,"discreta",6},
						 {2222,"AMI",8},
						 {2222,"aed",7},
						 {5555,"discreta",10},
						 {5555,"arquitectura",7},
						 {5555,"aed",8},
						 {3333,"AMI",9},							
						};

int main (){
	int len=7, pos=0, legAnterior, legPromMasAlto;
	float cantMateriasTotales=0,sumaNotasTotales=0, promedioTotal, promMasAlto=0; 
	float cantMateriasParciales=0,sumaNotasParciales=0, promedioParcial;

	while (pos < len){
		legAnterior = vecK1053[pos].leg;
		//inicializo antes de procesar cada grupo
		sumaNotasParciales=0;
		cantMateriasParciales=0;

		//proceso cada grupo
		while (legAnterior==vecK1053[pos].leg && pos<len){ //pos<len ->si no se terminó
			sumaNotasParciales+=vecK1053[pos].nota;
			cantMateriasParciales++;
			cantMateriasTotales++;
			sumaNotasTotales+=vecK1053[pos].nota;
			pos++;											//importante incrementar el pos
		}

		promedioParcial=sumaNotasParciales/cantMateriasParciales;
		cout<<"El estudiante de legajo "<<legAnterior<<" tiene el promedio "<<promedioParcial<<endl;
		if(promedioParcial>promMasAlto){
			legPromMasAlto=legAnterior;
			promMasAlto=promedioParcial;
		}
	}
	promedioTotal=sumaNotasTotales/cantMateriasTotales;
	cout<<"el promedio del curso fue "<<promedioTotal<<endl;
	cout<<"el estudiante que tuvo mayor promedio fue "<<legPromMasAlto<<endl;

	return 0;
}

