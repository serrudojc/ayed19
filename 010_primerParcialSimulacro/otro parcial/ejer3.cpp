/*se tiene un archivo "stock.dat" con todos los productos que se encuentran en stock (200 registros como maximo).
de cada producto sabemos su codigo (numerico), descripcion y su peso en Kg. el archivo no está ordenado.
Crear dos archivos "pesados.dat" y "livianos.dat" donde colocaremos los productos segun su peso, ordenados por codigo. 
Los pesados tiene un peso mayor o igual a 100kg, los livianos peso menor a 100kg.*/


struct Productos{
	int codigo;
	char descripcion[50];
	int peso;
}

Productos reg, auxPesados[200], auxLivianos[200];
int lenAuxLiv=0,lenAuxPes=0;

FILE * archStock = fopen("stock.dat","rb");

fread(&reg,sizeof(Productos),1,archStock);

while (!feof(archStock)){

	if (reg.peso <100){
		insertarOrdenado(auxLivianos, lenAuxLiv, reg); //tengo q ordenar por codigo, como? magia.
	}else{
		insertarOrdenado(auxPesados, lenAuxPes, reg); //ordenado por codigo (habria que tocar las funcion insertarOrdenado: magia)
	}
	fread(&reg,sizeof(Productos),1,archivo);
}
fclose(archStock);

FILE * archPesado = fopen("pesados.dat","wb");
FILE * archLiviano = fopen("livianos.dat","wb");

for (int i=0; i<lenAuxPes; i++){
	fwrite(&auxPesados[i], sizeof(Productos), 1, archPesado);
}
for (int i=0; i<lenAuxLiv; i++){
	fwrite(&auxLivianos[i], sizeof(Productos), 1, archLiviano);
}
fclose(archPesado);
fclose(archLiviano);