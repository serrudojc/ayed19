#include <iostream>
#include "vectores.hpp"
using namespace std;

int main(int argc, char** argv) {
	//Vectores con Struct - Ejercicio 1
	paisVelocidad paises[] = {{"Argentina",120,60},{"Uruguay",170,70},{"Chile",150,10}};
	int lenPaises = 3;
	int pos;
	float promedio;
	pos = buscarMinimo(paises,lenPaises);
	cout << paises[pos].pais << " tiene la velocidad minima que es " << paises[pos].velMinima << " Km/h" << endl;
	pos = buscarMaximo(paises,lenPaises);
	cout << paises[pos].pais << " tiene la velocidad maxima que es " << paises[pos].velMaxima << " Km/h" << endl;
	promedio = promedioVelocidadesMaximas(paises,lenPaises);
	cout << "El promedio de velocidades maximas es " << promedio << endl;
	return 0;
}
