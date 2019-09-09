/*	Crear un procedimiento que dados dos vectores con los datos de los estudiantes de dos cursos vecK1051 y vecK1052 (20 estudiantes max c/u) cree un 
archivo "estudiantes.dat" que contenga los estudiantes de ambos cursos ordenados por legajo. De los estudiantes sabemos el nombre, el legajo y el email. 
Los vectores se encuentran ordenados por legajo. En el archivo colocar ademas de los datos originales, el curso de donde proviene cada uno. */
#include <iostream>
#include <string.h>
using namespace std;


struct Est{
	int legajo;
	char nombre[50];
	char email[50];
};

struct EstCon{
	Est datos;
	char curso[5];
};
void consolidarCursos(Est vecK1051[], int lenK1051, Est vecK1052[], int lenK1052);
int main (){
	Est vecK1051[]={{1002,"pepe","pepe@gmail.com"},{1005,"pedro","pedro@gmail.com"},{1006,"lolo","lolo@gmail.com"}};
	Est vecK1052[]={{1003,"maria","maria@gmail.com"},{1007,"lala","lala@gmail.com"},{1020,"lola","lola@gmail.com"},{1030,"pepa","pepa@gmail.com"}};
	int lenK1051=3,lenK1052=4;

	consolidarCursos(vecK1051,lenK1051,vecK1052,lenK1052);
	return 0;
}

void consolidarCursos(Est vecK1051[], int lenK1051, Est vecK1052[], int lenK1052){
	//dos vectores ordenados por legajo: ESTRATEGIA: Apareo
	FILE * archivo = fopen ("estudiantes.dat","wb");
	int pos51=0, pos52=0;
	EstCon aux;

//hasta que los dos vectores NO se terminen
	while (pos51<lenK1051 && pos52<lenK1052){
		if(vecK1051[pos51].legajo < vecK1052[pos52].legajo){
			aux.datos = vecK1051[pos51];	//aux es de tipo de datos EstCon, aux.datos es de tipo datos Est. OJO CON LO TIPO DE DATOS 
			strcpy (aux.curso , "K1051");
			fwrite (&aux, sizeof(EstCon),1,archivo);
			pos51++;
		}else{
			aux.datos = vecK1052[pos52];
			strcpy (aux.curso , "K1052");
			fwrite (&aux, sizeof(EstCon),1,archivo);
			pos52++;
		}
	}
//cuando uno de los vectores terminó, sigo con el otro.
	while (pos51 < lenK1051){
			aux.datos = vecK1051[pos51];	 
			strcpy (aux.curso , "K1051");
			fwrite (&aux, sizeof(EstCon),1,archivo);
			pos51++;
	}
	while (pos52 < lenK1052){
			aux.datos = vecK1052[pos52];	 
			strcpy (aux.curso , "K1052");
			fwrite (&aux, sizeof(EstCon),1,archivo);
			pos52++;
	}	
	fclose(archivo);
}