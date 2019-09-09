/*
Dado un vector con 100 productos vendidos agrupados por ID de factura, calcular;
1- cual fue el total por factura?
2- cual fue la factura con mas unidades?
3-cual fue la factura de menos importe?
*/

#include <iostream>
using namespace std;

struct Fact
{	int idFact;
	int idItem;
	char desc[50];
	int cantidad;
	float precioU;
};

int main (){
	Fact vecProc[100];
	int len=100;
	int i=0;
	int idFactAnt=0;
	float totXFact;
	int MaxU=0;
	int idFactMax=0;
	int uniXFact;
	float menosI=999999;
	int idFactMin;

	while(i<len){
		idFactAnt=vecProc[i].idFact;
		totXFact=0;
		uniXFact=0;


		while(i<len && idFactAnt==vecProc[i].idFact){
			totXFact+=vecProc[i].precioU*vecProc[i].cantidad;
			uniXFact+=vecProc[i].cantidad;

			i++;
		}
		if(uniXFact>MaxU){
			MaxU=uniXFact;
			idFactMax=idFactAnt;
		}
		if(totXFact<menosI){
			menosI=totXFact;
			idFactMin=idFactAnt;
		}
		cout<<"Total de la factura "<<idFactAnt<<" es "<<totXFact<<endl;
	}
	cout<<"La factura con mas unidades fue "<<idFactMax<<endl;
	cout<<"la factura de menor importe fue"<<idFactMin<<endl;

	return 0;
}