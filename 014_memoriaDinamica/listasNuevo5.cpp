/*
Ejercicio Nro. 5:
Dado un archivo de registros de estudiantes (ARCHA). Se debe desarrollar el
programa que genere un archivo ARCHL igual al anterior pero ordenado por
número de legajo.
*/
struct Nodo{
	Alu info;
	Nodo* sig;
}
struct Alu{
	int legajo;
	int curso;
	char apellido[50];
}

FILE *archa = fopen("archa.dat","rb");
Alu reg;

//creo la lista
Nodo* lista = NULL;

fread(&reg, sizeof(Alu), 1, archa);
while(!feof(archa)){
	//mando a la lista
	insertarOrdenado(lista, reg);
	fread(&reg, sizeof(Alu), 1, archa);
}
fclose(archa);

//generamos nuestro nuevo archivo
FILE *archl = fopen("archl.dat","wb");

//voy recorriendo mi lista
while(lista != NULL){
	//me devuelve el campo dato
	reg = eliminarPrimerNodo(lista);
	fwrite(&reg. sizeof(Alu), 1, archl);
}
fclose(archl);
