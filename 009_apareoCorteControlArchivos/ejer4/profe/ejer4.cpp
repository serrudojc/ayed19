#include <iostream>
using namespace std;

struct Venta{
	int codArt;
	int cantVendida;
	float precioUnitario;
};

int main (){

	FILE* ventas = fopen("ventas052018.dat","rb");
	Venta reg;
	int codArtAnt;
	float ventasMes=0;
	int cantVendxArt;
	int maximoUnidades=0;
	int codArtMax=0;

	fread(&reg, sizeof(Venta),1,ventas);

	while(!feof(ventas)){
		codArtAnt = reg.codArt;
		cantVendxArt=0;

		while(reg.codArt==codArtAnt && !feof(ventas)){

			ventasMes+=reg.cantVendida*reg.precioUnitario;
			cantVendxArt+=reg.cantVendida;

			fread(&reg, sizeof(Venta),1,ventas);

		}
		if(cantVendxArt>maximoUnidades){
			maximoUnidades=cantVendxArt;
			codArtMax=codArtAnt;
		}
		cout<<"cantidad vendidda del art "<<codArtAnt<<cantVendxArt<<endl;
			
	}
	cout<<"ventas facturadas en el mes "<<ventasMes<<endl;

	cout<<"artculo mas vendido "<<codArtMax<<endl;


	fclose(ventas);
	return 0;
}