// Final 23 02 2017 Lista con Sublista
// 1. 
//lista de cursos.
struct Curso{
	InfoCurso info;
	Curso *sig;
};

struct InfoCurso{
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Estudiante *estudiantes;
}

struct Estudiante{
	InfoEst info;
	Estudiante *sig;
};

struct InfoEst{
	int id;
	Evaluacion *evaluaciones[4]; //ver dibujo en carpeta
}
/*Los registros están parcialmente ordenados, para un estudiante y para una evaluación determinada, la
primera nota es la de la instancia original, la segunda es la del recuperatorio, y la tercera la del segundo
recuperatorio. No hay otro orden definido.
ESTO ES ASI, ASI A MEDIDA QUE INSERTO LA QUE ME VA QUEDANDO ES LA ULTIMA
*/

struct Evaluacion{
	int nota;
	Evaluacion *sig;
}

//2. Supongo que paro el archivo abierto
//nos falta la estructura del archivo, novedades. Esto es lo que vamos a leer del archivo
struct novedad{
	int idCurso;
	int idEst;
	int parcial;
	int nota;
}
//inicializo la lista 
Curso* curso = NULL;

void ProcesarNovedades(FILE* arch, Curso* &cursos){
	novedad reg;
	fread(&reg, sizeof(novedad),1,arch);
	while(!feof(arch)){

		AgregarNota(curso, reg.idCurso, reg.idEst, reg.parcial, reg.nota);

		fread(&reg, sizeof(novedad),1,arch);
	}
	fclose(arch);
}
//------------------------------------------------------
//3
AgregarNota(Curso* &curso, int idCurso, int idEst, int parcial, int nota){

	Curso* cursoBuscado = buscar(cursos, idCurso);
	Estudiante* estBuscado = buscar(cursoBuscado, idEst);
	AgregarNodo (estBuscado->info.evaluaciones[parcial-1], nota);
}
//no usamos insertarOrdenado, pq va atrás. 1ra instancia, 1er rec, 2 rec, etc, el que vale va quedar atras de todo. No hay que ordenar
//4 -----------------------------------------------------

void calcularEstadisticas(Curso* cursos){
	//si tenemos que actualizar, necesitamos un auxiliar para no perder la referencia
	Curso* aux = cursos;

	//voy a necesitar estos para recorrer estudiantes
	Estudiante* auxEst = NULL;
	//voy a recorrer
	while(aux != NULL){
		//aux apunta a muchos estudiantes. tengo que recorrer la lista de estudiantes
		auxEst = aux->info.estudiantes
		//recorro la lista de estudiantes
		while(auxEst != NULL){
			//a getEstado le paso el arreglo de notas
			switch(getEstado(auxEst->info.evaluaciones)){
				case 1: //promociona, tengo que acceder al info del curso
						aux->info.promocionados++;
						break;
				case 2: aux->info.regularizados++;
						break;
				case 3: aux->info.recursantes++;
						break;
			}
			auxEst = auxEst->sig;
		}
		//avanzo
		aux = aux->sig;
	}
}

//5 getEstado  ------------------------------------
//recibe un vector de listas,
int getEstado(Evaluacion *evaluaciones[4]){
	//segun la nota, ver que se sacó. Tengo mi arreglo de listas
	
	//tengo que recorrer dos cosas, la lista de notas y mi vector de evaluaciones
	Evaluacion* aux;

	//uso un vector
	int vecNotas[4];

	//recorro el vector
	for(int i=0; i<4; i++){
		//ahora recorro la lista de notas
		//necesito el auxiliar que cree antes
		aux = evaluaciones[i];
		//recorremos el aux, uno antes de NULL pq necesitamos el ultimo valor
		while(aux->sig != NULL){
			//me importa la ultima nota
			aux = aux->sig;
		}
		vecNotas[i] = aux->nota;
	}
	//recorremos el vector que creamos
	int situacion;
	
	int masDeOcho = 0;
	int entreSeisYOcho = 0;
	int menosDeSeis = 0;

	for(int i=0; i<4; i++){
		if(vecNotas[i]>=8)
			masDeOcho++;
		else if(vecNotas[i]>=6)
			entreSeisYOcho++;
		else
			menosDeSeis++;

		if(menosDeSeis>0)
			situacion = 3;
		else if(entreSeisYOcho>0)
			situacion = 2;
		else
			situacion = 1;
	}


	return situacion;
}
