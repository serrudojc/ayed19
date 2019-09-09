#include <iostream>
using namespace std;

struct Venta{
	int codArt;
	int cantVendida;
	float precioUnitario;
};

struct Venta reg;
FILE *archivo;

int main (){
	float ventasMes=0;
	archivo = fopen("ventas052018.dat","rb");

	fread(&reg, sizeof(reg),1,archivo);

	cout<<"codArt"<<"\t"<<"cantVendida"<<"\t"<<"precioUnitario"<<endl;

	while(!feof(archivo)){
		cout<<reg.codArt<<"\t\t"<<reg.cantVendida<<"\t\t"<<reg.precioUnitario<<endl;

//ventas facturas en el mes.
		ventasMes+=reg.cantVendida*reg.precioUnitario;

//cantidad de ventas de cada articulo

//el articulo mas vendido



		fread(&reg, sizeof(reg),1,archivo);
	}
	fclose(archivo);

	cout<<"Ventas Facturadas en el mes: "<<ventasMes<<endl;

	return 0;
}