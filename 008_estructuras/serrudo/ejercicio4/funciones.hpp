#include<string>
using namespace std;

struct alumnosStruct {
	string nombre;		//CONSULTAR: no hay que declarar tipo array tipo char? ej: char materia[20];
	int legajo;
	int nota;
};
#ifndef funciones//CONSULAR: ifdef, define, endif
#define funciones

int buscar(alumnosStruct arr[], int len, string nom);
void modificar(alumnosStruct arr[], int pos, int newNota);
float promedio(alumnosStruct arr[], int len);
int buscarMejor(alumnosStruct arr[], int len);
int buscarMenor(alumnosStruct arr[], int len);

#endif