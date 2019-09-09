#include <iostream>
#include "funciones.hpp"
using namespace std;

int main (){

	notasDatos notas[]={{"probabilidad",50},
						{"algoritmos",40},
						{"arquitectura",35},
						{"legislación",18},
						{"discreta",68},
						};
	int lenNotas = 5, pos;
	float prom;


	pos = buscarMaximo(notas,lenNotas);
	cout<<notas[pos].materia<<" fue la materia con mayor inscriptos: "<<notas[pos].inscriptos<<endl;

	pos = buscarMinimo(notas,lenNotas);
	cout<<notas[pos].materia<<" fue la materia con menor inscriptos: "<<notas[pos].inscriptos<<endl;

	prom= promedio(notas, lenNotas);
	cout<<"promedio de inscriptos en total fue de "<<prom<<" alumnos"<<endl;

	return 0;
}
