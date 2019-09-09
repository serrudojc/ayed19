#include <iostream>
#include <string.h>
using namespace std;

struct Nota {
	int legajo;
	char materia[50];
	float nota;
};

int main (){
	int legajoAnt, cantNotasProcesadas=0, promTotal;//prom como float!!!
	float sumaNotasTotal=0;

	FILE * archivo = fopen("notas.dat","rb");
	Nota reg;

	fread (&reg, sizeof(Nota),1,archivo);

	while (!feof(archivo)){
		float notaMasAlta=0;
		char materiaNotaMasAlta[50];
		legajoAnt=reg.legajo;

		while(!feof(archivo) && reg.legajo==legajoAnt){
			cantNotasProcesadas++;

			sumaNotasTotal+=reg.nota;

			if(reg.nota>notaMasAlta){
				notaMasAlta=reg.nota;
				strcpy (materiaNotaMasAlta,reg.materia);
			}	
			fread (&reg, sizeof(Nota),1,archivo);
		}
	cout<<"estudiante "<<legajoAnt<<" tuvo nota mas alta: "<<notaMasAlta<<" materia: "<<materiaNotaMasAlta<<endl;
	}

	cout<<"Cantidad de notas procesadas: "<<cantNotasProcesadas<<endl;
	promTotal=sumaNotasTotal/cantNotasProcesadas;
	cout<<"promedio de calificaciones total: "<<promTotal;

	return 0;
}