
//tipo y subtipo me van a permitir insertar un nuevo nodo en la matriz.

NodoSospechoso *matrizSospechosos[4][9];	//[tipo][mayor subtipo]

struct NodoSospechoso{
	sospechoso info;
	NodoSospechoso *sig;	
}

struct sospechoso{
	int dni;
	char apeNom[50];
	//sublista al numero de dedo
	Dedo *dedos;
}

struct Dedo{
	int nroDedo;
	Dedo *sig;
}

//tipo nuevo para crear el registro al leer el archivo
struct archSospe{
	int dni;
	char apeNom[50];
	int dedo;
	int tipo;
	int subtipo;
}

//------------------------------------------------------------------------
//Punto 1
void cargarMatrizSospechoso(NodoSospechoso *matrizSospechosos[4][9]){
	//abrimos el archivo
	FILE *sospe = fpen("sospe.dat","rb");
	archSospe reg; 
	sospechoso auxSospe;
	NodoSospechoso *nodoBuscado;

	fread(&reg, sizeof(archSospe),1,sospe);
	while(!feof(sospe)){
		//cargamos la matriz
		//que pasa si ya existe el sospechoso? si ya está cargado

		//No se aun si está
		auxSospe.dni = reg.dni;
		strcpy(apeNom, reg.apeNom);
		auxSospe.dedos = NULL; // estamos haciendo un nodo del tipo de datos a buscar. No se si está o no está 
		//busca e insertamos ordenado. TENGO que aclarar "ordenado por nombre"
		nodoBuscado = buscaEInsertaOrdenado(matrizSospechosos[reg.tipo-1][reg.subtipo-1], auxSospe);
		//hasta ahora me devolvió el sospechoso que me interesa. 
		//Ahora tengo que ubicar los dedos, que es una lista
		insertarOrdenado(nodoBuscado->info.dedos, reg.dedo);
		fread(&reg, sizeof(archSospe),1,sospe);
	}
	fclose(sospe);
}
//-----------------------------------------------------------------------
void emitirSospechosos (NodoSospechoso *matrizSospechosos[4][9], int tipo, int subtipo){
	//pongo la lista en un aux para no perder mi referencia
	NodoSospechoso *auxListSospe = matrizSospechosos[tipo-1][subtipo-1];
	Dedo *auxDedos;
	//itero sobre mi lista
	while(auxListSospe != NULL){
		cout<<"DNI "<<auxListSospe->info.dni;
		cout<<"Ape y Nom "<<auxListSospe->info.apeNom;
		//ahora imprimimos los dedos con su nombre y en que mano estan
		//Dedod es una lista, 
		//para no perder la referencia necesito una auxiliar
		auxDedos = auxSospe->info.dedos;
		//recorro
		while(auxDedos != NULL){
			//accedo al numero de dedos, pero no me dice nada. Tengo que ver de que mano y dedo es
			switch(auxDedos->nroDedo){
				case 1: 
				case 6:
						cout<<"pulgar"<<endl; break;
				case 2:
				case 7:
						cout<<"indice"<<endl; break;
				case 3: 
				case 8:
						cout<<"mayor"<<endl; break;
				case 4: 
				case 9:
						cout<<"anular"<<endl; break;
				case 5: 
				case 10:
						cout<<"meñique"<<endl; break;				
			
			}
			if (auxDedos->nroDedo >= 1 && auxDedos->nroDedo <= 5)
				cout<<"mano derecha"<<endl;
			else
				cout<<"mano izquierda"<<endl;
		//hasta ahora solo imprimí un  solo dedo, tengo que avnzar
			auxDedos = auxDedos->sig;
		}
		auxListSospe = auxListSospe->sig;
	}
}