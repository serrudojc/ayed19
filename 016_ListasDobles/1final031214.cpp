//FInal 3/12/2014

//primer punto

struct infoPiso{
	int piso;
	int suben; //personas que suben (deberia ser positivo siempre?)
	int bajan; //personas que bajan
}

//declaramos el nodo
struct Nodo{
	infoPiso info;
	Nodo* arriba;
	Nodo* abajo;
}
//-------------------------------------------------------------------------------------------------------------

//segundo punto. Prototipo
//(devuelve distancia planta baja) insertarPisoArribaDelActualYMedir( , , entrada, salida)
int insertarPisoArribaDelActualYMedir(Nodo* &unPisoNuevo, Nodo* &elPisoActual, int &masBajo, int &masAlto);
	
//--------------------------------------------------------------------------------------------------------------

//tercer punto.
int insertarPisoArribaDelActualYMedir(Nodo* &unPisoNuevo, Nodo* &elPisoActual, int &masBajo, int &masAlto){
	//Ver grafico en carpeta
	//insertarPisoArribaDelActual, reasignando punteros. NO SACO, sino pierdo referencias
	//1
	unPisoNuevo->arriba = elPisoActual->arriba;
	//2
	unPisoNuevo->abajo = elPisoActual;
	//3
	elPisoActual->arriba->abajo = unPisoNuevo;
	//4
	elPisoActual->arriba = unPisoNuevo;


	//medirDistanciaAPisosExtremos
 	void medirDistanciaAPisosExtremos(Nodo* unPisoNuevo, int& masBajo, int &masAlto);


	//medirDistanciaPlantaBaja
	Nodo* aux = unPisoNuevo; //asignamos un pisoNuevo
	int distPlantaBaja = 0; 
	//accedo al piso, con el piso nuevo, el que inserto
	//si es mayor a cero, voy para abajo
	//depende del if que entre, avanzamos para abajo o para arriba
	if(unPisoNuevo->info.piso > 0){
		//ahora si voy a recorrer
		while(aux != NULL && aux->info.piso != 0){
			distPlantaBaja++;
			//avanzo para abajo
			aux = aux->abajo
		}
	}
	//
	if(unPisoNuevo->info.piso < 0){
		while(aux != NULL && aux->info.piso != 0){
			distPlantaBaja++;
			aux = aux->arriba;
		}
	}

	//esto es lo que retorna la funcion insertarPisoArribaDelActualYMedir
	return distPlantaBaja;
}

//-----------------------------------------------------------------------------------------
//Cuarto Punto

 void medirDistanciaAPisosExtremos(Nodo* unPisoNuevo, int& masBajo, int &masAlto){
 //tendriamos que contar para medir distancia, recorrer para arriba y para abajo
 //recorremos para abajo
	Nodo* punteroAbajo = unPisoNuevo->abajo;

	while(punteroAbajo != NULL){
		masBajo++;
		punteroAbajo = punteroAbajo->abajo;
	}

	//para arriba, usamos otro auxiliar
	Nodo* punteroArriba = unPisoNuevo->arriba;
	while(punteroArriba != NULL){
		masArriba++;
		punteroArriba = punteroArriba->arriba;
	}
}