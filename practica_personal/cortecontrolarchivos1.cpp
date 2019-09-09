#include <iostream>
using namespace std;

struct Venta
{	int codArt;
	int cantVendida;
	float precioUnitario;	
};

Venta reg;

int main (){

	float vtasMes=0;
	int artMasVendido, cantArtMasVendido=0, articuloAnterior;

	FILE * arch = fopen("ventas052018.dat","rb");
	fread(&reg,sizeof(Venta),1,arch);

	while (!feof(arch)){
		
		articuloAnterior = reg.codArt;
		int cantVendidaXarticulo=0;

		while(!feof(arch) && articuloAnterior==reg.codArt){
			cantVendidaXarticulo+=reg.cantVendida;
			vtasMes+=reg.cantVendida*reg.precioUnitario;
			fread(&reg,sizeof(Venta),1,arch);
		}
		if (cantArtMasVendido<cantVendidaXarticulo){
			artMasVendido=articuloAnterior;
			cantArtMasVendido=cantVendidaXarticulo;
		}
				
		cout<<articuloAnterior<<" "<<cantVendidaXarticulo<<" "<<endl;
	}
	cout<<endl;
	cout<<"Vtas del mes: "<<vtasMes<<endl;
	cout<<"art mas vendido: "<<artMasVendido<<endl;
	fclose(arch);
	return 0;
}