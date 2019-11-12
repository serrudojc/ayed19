/* final 15/07/16
*/

//estructura de candidatos
struct candidato{
	string nombreCandidato;
	string nombreLista;
	float posicion;
};

//vectores de candidatos
candidato vecCandidato[15];
candidato vecResultado[5];


//para no devolverlo, se crea en un programa ppal y le pasamos las dos estructuras


void generarListaConsejerosDocentes(candidato vecCandidato[], candidato vecResultado[]){
	//hacemos las divisiones

	int votos[] = {votosL1, votosL2, votosL3}
	//candidatos ordenados por listas


	//structura auxiliar. Tengo que hacer el promedio de todos y luego ordenar
	candidato vecAux[15;]
	int posVec = 0;

	//primero por cantidad de votos
	for(int i=0; i<3; i++){

		//luego iteramos por cntidad de candidatos
		for(j=0; j<5; j++){
			vecAux[posVec].nombreCandidato = vecCandidato[posVec].nombreCandidato;
			vecAux[posVec].nombreLista = vecCandidato[posVec].nombreLista;
			vecAux[posVec].posicion = votos[i]/(j+1);
			posVec++;
		}
	}
	//ahora ordenamos
	ordenarVector(vecAux, 15); //criterio: posicion decreciente

	//cargamos vector de resultados
	for(int i; i<5; i++){
		vecResultado[i] = vecAux[i];
		vecResultado[i].posicion = i++;
	}
}