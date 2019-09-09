//resuelto profe

struct depositos
{	int nroArt; //ordenados por nurmero de articulo
	char desc[50];
	int cant;
};
struct depoConNombre
{	depositos art;
	char nombre[20];	
};

depositos reg1, reg2;
depoConNombre regS;

FILE *d1 = fopen("deposito1.dat","rb");
FILE *d2 = fopen("deposito2.dat","rb");
FILE *stock =fopen("stock.dat","wb");

fread(&reg1, sizeof(depositos), 1, d1);
fread(&reg2, sizeof(depositos), 1, d2);

while (!feof (d1) && !feof(d2)){
	if( reg1.nroArt < reg2.nroArt){
		regS.art=reg1;
		strcpy(regS.nombre,"depo1");
		fwrite(&regS,sizeof(repoConNombre),1,stock);
		fread(&reg1, sizeof(depositos), 1, d1);
	}else{
		regS.art=reg2;
		strcpy(regS.nombre,"depo2");
		fwrite(&regS,sizeof(repoConNombre),1,stock);
		fread(&reg2, sizeof(depositos), 1, d2);
	}

while(!feof (d1)){
	regS.art=reg1;
	strcpy(regS.nombre,"depo1");
	fwrite(&regS,sizeof(repoConNombre),1,stock);
	fread(&reg1, sizeof(depositos), 1, d1);
}
while(!feof (d2)){
	regS.art=reg2;
	strcpy(regS.nombre,"depo2");
	fwrite(&regS,sizeof(repoConNombre),1,stock);
	fread(&reg2, sizeof(depositos), 1, d2);
}
fclose(d1);
fclose(d2);
fclose(stock);