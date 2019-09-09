#include<string>
using namespace std;
#define CANT 5
struct stockArticulos {
	string nombre;		//CONSULTAR: no hay que declarar tipo array tipo char? ej: char materia[20];
	int cod;
	int pre;
	int cant;
};
#ifndef funciones//CONSULAR: ifdef, define, endif
#define funciones

void agregar(stockArticulos arr[], int n, int& len);
int buscar(stockArticulos arr[], int len, string nom);
void modificar(stockArticulos arr[], int pos, int precio, int cantidad);
#endif