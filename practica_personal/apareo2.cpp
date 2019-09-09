#include <iostream>
using namespace std;

struct Estudiantes{
	int legajo;
	char apellido[50];
	float promedio;
};

struct Estudiantes K1051[3]={{1003,"ramirez",8},{1006,"perez",9},{1010,"rodriguez",4}};
struct Estudiantes K1052[4]={{1004,"alvarez",9},{1008,"lucas",3},{1007,"mirko",4},{1011,"marisol",1}};
struct Estudiantes Consolidado[20];

int main (){

int posK1051=0,posK1052=0,lenK1051=3,lenK1052=4,posConsolidado=0,lenConsolidado=0;
int i=0;
//------------------------------------------------
	while (posK1051<lenK1051 && posK1052<lenK1052){
		if (K1051[posK1051].legajo < K1052[posK1052].legajo){
			Consolidado[posConsolidado]=K1051[posK1051];
			posK1051++;
		}else{
			Consolidado[posConsolidado]=K1052[posK1052];
			posK1052++;
		}
		lenConsolidado++;
		posConsolidado++;
	}
//-----------------------------------------------------
	while(posK1051<lenK1051){
		Consolidado[posConsolidado]=K1051[posK1051];
		posK1051++;
		lenConsolidado++;
		posConsolidado++;
	}
	while(posK1052<lenK1052){
		Consolidado[posConsolidado]=K1052[posK1052];
		posK1052++;
		lenConsolidado++;
		posConsolidado++;
	}
	//-----------------------------------------------------
	cout<<endl;
	while(i<lenConsolidado){
		cout<<Consolidado[i].legajo<<" "<<Consolidado[i].apellido<<" "<<Consolidado[i].promedio<<endl;
		i++;
	}
	return 0;
}