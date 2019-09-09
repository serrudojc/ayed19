#include<string>
using namespace std;
struct notasDatos {
	string materia;		//CONSULTAR: no hay que declarar tipo array tipo char? ej: char materia[20];
	int inscriptos;
};
//#ifndef funciones//CONSULAR: ifdef, define, endif
//#define funciones

int buscarMinimo(notasDatos arr[], int len);
int buscarMaximo(notasDatos arr[], int len);
float promedio(notasDatos arr[], int len);

//#endif
