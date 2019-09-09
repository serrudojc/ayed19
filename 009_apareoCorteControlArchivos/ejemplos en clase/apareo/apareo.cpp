/*Ejemplo de clase 5/6/19
Si los vectores están ordenados, usamos APAREO

-------------------------------------------------------------------
Ejemplo APAREO GENERICO (para usar esto, nos deben decir que los vectores ya vienen ordenados)

struct TipoDeDato {
	int clave;
	... etc
}

int lenA=3, posA=0, TipoDeDato vecA[10];
int lenB=3, posB=0, TipoDeDato vecB[10];
int lenC=3, posC=0, TipoDeDato vecC[10];

while ( posA<lenA  &&  posB<lenB){
	if( vecA[posA].clave < vecB[posB].clave){
	vecC[posC]=vecA[posA];
	posA++;
	}else{
	vecC[posC]=vecB[posB];
	posB++;
	}
	posC++;
	lenC++;
}
						//cuando uno de los vectores acaba, pero aun sigue habiendo valores en el otro, hago:
while(posA<lenA){
	vecC[posC]=vecA[posA];
	posA++;
	posC++;
	lenC++;
}
while(posB<lenB){
	vecC[posC]=vecB[posB];
	posB++;
	posC++;
	lenC++;
}
---------------------------------------------------------------------
*/

# include <iostream>
using namespace std;
#include <string>

struct Estudiante{
	int legajo;
	char apellido[50];
};


Estudiante vecCursoA [3]={{1,"Perez"},{10,"Gonzalez"},{24,"Diaz"}};
Estudiante vecCursoB [2]={{2,"Lopez"},{15,"Alvarez"}};
Estudiante vecConsolidado [5];

/*para el apareo se ncesita mas de una estructura (vector, archivo lista)
ORDENADA por el campo que deseamos intercalar 
*/

int main (){
	int lenA=3, posA=0, lenConsolidado=0;
	int lenB=2, posB=0, posConsolidado=0;

//imprimo structs
	for (int i=0;i<lenA;i++){
		cout<<vecCursoA[i].legajo<<" "<<vecCursoA[i].apellido<<endl;
	}
	cout<<endl;
	for (int i=0;i<lenB;i++){
		cout<<vecCursoB[i].legajo<<" "<<vecCursoB[i].apellido<<endl;
	}
	cout<<endl;
//termino de imprimir structs

	while (posA<lenA && posB<lenB){
		if (vecCursoA[posA].legajo < vecCursoB[posB].legajo){
			vecConsolidado[posConsolidado] = vecCursoA[posA];
			posA++;
		}
		else{
			vecConsolidado[posConsolidado] = vecCursoB[posB];
			posB++;
		}
		posConsolidado++;
		lenConsolidado++;
	}
//si se acaba A entro aca
	while (posA < lenA){
		vecConsolidado[posConsolidado] = vecCursoA[posA];
		posA++;
		posConsolidado++;
		lenConsolidado++;
	}
//si se acaba B entro aca
	while (posB < lenB){
		vecConsolidado[posConsolidado] = vecCursoB[posB];
		posB++;
		posConsolidado++;
		lenConsolidado++;
	}
//imprimo resultados
	cout<<"---------------------"<<endl;

	for (int i=0;i<lenA;i++){
		cout<<vecCursoA[i].legajo<<" "<<vecCursoA[i].apellido<<endl;
	}
	cout<<endl;
	for (int i=0;i<lenB;i++){
		cout<<vecCursoB[i].legajo<<" "<<vecCursoB[i].apellido<<endl;
	}
	cout<<endl;
	for (int i=0;i<lenConsolidado;i++){
		cout<<vecConsolidado[i].legajo<<" "<<vecConsolidado[i].apellido<<endl;
	}

	return 0;
}