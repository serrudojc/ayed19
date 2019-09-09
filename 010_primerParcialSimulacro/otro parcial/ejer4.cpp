/* 4- se tiene un archivo "notas.dat" qe contiene los sig datos: numero de legajo, nombre de materia y nota.
el nombre de materia aparece solo 1 vez por estudiante. El archivo se encuentra ordenado por legajo. Se pide:
a) cual es el promedio gral de todos los estudiantes e informarlo por pantalla.
b) cual es el promedio de cada estudiante y grabarlo en un archivo "promedios.dat" que contenga el numero de 
legajo y promedio. */

struct PromediosEstudiantes{
	int legajo;
	float promedio;
}
struct Notas{
	int legajo;
	char materia[50];
	float nota;
};
PromediosEstudiantes promEstAux;
Notas reg;

int legAnt, alumNotasGral=0;
float sumaNotasGral=0, promGral;

FILE * archivo = fopen("notas.dat","rb");
FILE * arch = fopen("promedios.dat","wb");

fread (&reg, sizeof(PromediosEstudiantes), 1, archivo);

while (!feof (archivo)){
	legAnt=reg.legajo;
	int alumMaterias=0; //cuento cuantas materias de cada alumno, para sacar prom individual
	float sumaNotasAlum=0;

	while(!feof(archivo) && legAnt==reg.legajo){
		sumaNotasGral+=reg.nota;
		alumNotasGral++	//cuento cuantos alumnos, para sacar prom General. NOTA: es lo mismo sumar todas las notas y dividir por la cantidad de materias que sacar promedio de cada alumno, sumar promedios y dividir por cant de alumnos
//ambas son "iguales", pero las dos primeras se reinician con un nuevo estudiante.
		alumMaterias++;
		sumaNotasAlum+=reg.nota;

		fread (&reg, sizeof(PromediosEstudiantes), 1, archivo);
	}

	promEstAux.legajo= legAnt;
	promEstAux.promedio= sumaNotasAlum/alumMaterias;
	fwrite(&promEstAux, sizeof(PromediosEstudiantes), 1, arch);
}
promGral=sumaNotasGral/alumNotasGral;
cout<<"Punto a) Promedio General: "<<promGral;

fclose(archivo);
fclose(arch);