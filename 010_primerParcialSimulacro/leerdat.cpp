#include <iostream>
using namespace std;

struct leer{
		int legajo;
		char nombre[50];
		char email[50];
		char curso[5];
	};

int main (){
	leer reg;

	FILE * archivo = fopen("estudiantes.dat","rb");
	fread(&reg,sizeof(leer),1,archivo);

	while (!feof(archivo)){
		cout<<reg.legajo<<" "<<reg.nombre<<" "<<reg.email<<" "<<reg.curso<<endl;
		fread(&reg,sizeof(leer),1,archivo);
	}
	


	return 0;
}