#include <iostream>
using namespace std;


void unionvectores (int vecA[], int lenA, int vecB[],int lenB, int vecC[], int &lenC){
	bool enc;		//no lo uso

	for(int i=0;i<lenA;i++){
		buscaEInserta(vecC,lenC,vecA[i],enc);		//si no está, lo inserta
	}

	for(int i=0;i<lenB;i++){
		buscaEInserta(vecC,lenC,vecB[i],enc);	//reemplaza a buscar y a insertar.
	}
}

int main (){

	return 0;
}