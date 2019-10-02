// Final 23 02 2017 Lista con Sublista


/* 1. 
*/

struct Curso{
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Estudiante estudiantes;
	Curso* sig;
};

Curso* cursos;

struct Estudiante{
	int id;
	Evaluacion notas[4];
	Estudiante* sig;
};

//esto seria un "array" entre 0 y 3 de notas[i]?
struct Evaluacion{
	int datos;
	Evaluacion* sig;
};

//2.





