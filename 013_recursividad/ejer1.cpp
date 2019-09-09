//resuelto profe

struct depositos
{	int nroArt; //ordenados por nurmero de articulo
	char desc[50];
	int cant;	
};

struct depositos reg1, reg2;

FILE *d1 = fopen("deposito1.dat","rb");
FILE *d2 = fopen("deposito2.dat","rb");
FILE *stock =fopen("stock.dat","wb");

fread(&reg1, sizeof(depositos), 1, d1);
fread(&reg2, sizeof(depositos), 1, d2);

while (!feof (d1) && !feof(d2)){
	if( reg1.nroArt < reg2.nroArt){
		fwrite(&reg1,sizeof(depositos),1,stock);
		fread(&reg1, sizeof(depositos), 1, d1);
	}else{
		fwrite(&reg2,sizeof(depositos),1,stock);
		fread(&reg2, sizeof(depositos), 1, d2);
	}

while(!feof (d1)){
	fwrite(&reg1,sizeof(depositos),1,stock);
	fread(&reg1, sizeof(depositos), 1, d1);
}
while(!feof (d2)){
	fwrite(&reg2,sizeof(depositos),1,stock);
	fread(&reg2, sizeof(depositos), 1, d2);
}
fclose(d1);
fclose(d2);
fclose(stock);