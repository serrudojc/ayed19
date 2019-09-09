/*		Se tiene un archivo "ventas.dat" que contiene: numero de cliente, articulo comprado, cantidad comprada y precio unitario.
El articulo comprado solo aparece 1 vez por cliente. El archivo se encuentra ordenado por cliente. Calcular e informar:
	a) Cliente que mas dinero gastó.
	b) Cliente que menos cantidad de articulos compró
	c) cuanto dinero gastó cada cliente
	d) De cada cliente, el articulo más comprado. */

struct venta{
	int nroCli;
	char arti[50];
	int cant;
	float preU;
}

FILE * arch = fopen("ventas.dat","rb");
//CORTE CONTROL, pq está agrupado por nro cliente
venta reg; 

int nroCliAnt;

int cliMaxGasto;
float MaxGasto=0;

float gastoXCliente;

int maxCantCli;
char maxCantArtXCli; 

int cantXCli;
int minCant= 9999999;
int minCli;

fread(&reg, sizeof(venta), 1, arch);
while(!feof(arch)){
	nroCliAnt = reg.nroCli;
	gastoXCliente=0;
	maxCantCli=0;
	cantXCli=0;
	strcpy (maxCantArtXCli,""); //inicializamos en vacio el char

	while(!feof(arch) && reg.noCli==nroCliAnt){
		gastoXCliente += reg.cant*reg.preU;
		if(reg.cant > maxCantArtXCli){
			maxCantXCli = reg.cant;
			strcpy(maxCantArtXCli, reg.arti);
		}
		cantXCli += reg.cant;
		fread(&reg,sizeof(venta),1,arch);
	}	//cierro while chico
	if (gastoXCliente > MaxGasto){
		cliMaxGasto = nroCliAnt;
		MaxGasto = gastoXCliente;
	}
	if (cantXCli < minCant){
		minCant = cantXCli;
		minCli = nroCliAnt;
	}
	cout<<"el cliente "<< nroCliAnt <<"gastó"<< gastoXCliente <<endl;
	cout<<"el cliente "<< nroCliAnt <<"compro mas"<< maxCantArtXCli <<endl;
}	//cierro while grande
cout<<"el cliente "<< cliMaxGasto <<"es el que mas gasto"<<endl;
cout<<"el cliente "<< minCli <<"es el que menos articulos compró"<<endl;
fclose (arch);