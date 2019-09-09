#include<string>
using namespace std;
struct paisVelocidad {
	string pais;
	float velMaxima;
	float velMinima;
};
#ifndef vectores
#define vectores

int buscarMinimo(paisVelocidad arr[], int len);
int buscarMaximo(paisVelocidad arr[], int len);
float promedioVelocidadesMaximas(paisVelocidad arr[], int len);

#endif
