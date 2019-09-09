#include <iostream>
#include <string.h>
using namespace std;

struct Nota
{ 	int legajo;
	char materia[50];
	float nota;	
};

int main (){
	FILE* notas = fopen("notas.dat","rb");

	Nota reg;
	int legAnt;
	int NotasProc=0;
	float sumaNotas=0;
	//int cantEst=0;
	float NotaMax=0;
	char nombreMax[50];

	fread(&reg,sizeof(Nota),1,notas);

	while(!feof(notas)){
		legAnt=reg.legajo;
		//cantEst++;
		NotaMax=0;
		strcpy(nombreMax,"");


		while(!feof(notas) && legAnt==reg.legajo){
			NotasProc++;
			sumaNotas+=reg.nota;
			if(reg.nota>NotaMax){
				NotaMax=reg.nota;
				strcpy(nombreMax,reg.materia);
			}
			fread(&reg,sizeof(Nota),1,notas);
		}
		cout<<"el estudiante "<<legAnt<<" tiene la nota mas alta, es "<<nombreMax<<endl;

	}
	cout<<"cantidad de notas procesadas: "<<NotasProc<<endl;
	cout<<"promedio de los estudiates: "<<sumaNotas/NotasProc<<endl;

	fclose(notas);
	return 0;
}