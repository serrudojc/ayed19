/*
ARCHIVOS
Se tienen 4 archivos, “estudiantes.dat”, “docentes.dat”, “graduados.dat”, “nodocentes.dat”. 
Cada uno de los archivos contiene el nombre y el legajo de cada integrante 
(no precisamente se encuentran ordenados). Se pide crear un archivo 
“consolidado.dat”, que consolide todos los registros de los 4 archivos, describiendo 
cada persona por nombre, legajo y claustro al que pertenece. Este archivo debe estar 
ordenado por legajo. Mostrar por pantalla cómo quedó el archivo ordenado.
Nota: Los 4 archivos contienen un máximo de 10 registros cada uno.
*/

struct personaUniversitaria{
	int legajo;
	char nombre[50];
};

struct personaConsolidada{
	personaUniversitaria per;
	char claustro[20];
};

//Primero: abro archivos
FILE *est = fopen("estudiantes.dat","rb");
FILE *doc = fopen("docentes.dat","rb");
FILE *noDoc = fopen("noDocentes.dat","rb");
FILE *gra = fopen("graduados.dat","rb");

//Segundo: ahora necesitamos la estructura donde vamos a guardar
personaConsolidada cons[40];
int lenCons = 0;

//empezamos a procesar los archivos. DEFINIMOS UN REGISTRO
personaUniversitaria reg;
personaUniversitaria aux;

fread(&reg, sizeof(personaUniversitaria), 1, est);

//hasta que no sea fin de archivo, proceso
while(!feof(est)){
	//insertarOrdenado(cons, lenCons, reg); NO PUEDO HACER ESTO AUN!. Me falta el claustro
	aux.per = reg;
	strcpy(aux.claustro, "estudiante");

	insertarOrdenado(cons, lenCons, aux); //lo voy a ordenar por legajo.
	fread(&reg, sizeof(personaUniversitaria), 1, est);	//siempre volver a leer,si no, no avanzo
}
//termino de procesar mi archivo estudiante
fclose(est);

//ahora con docentes
fread(&reg, sizeof(personaUniversitaria), 1, doc);
while(!feof(est)){
	aux.per = reg;
	strcpy(aux.claustro, "docente");

	insertarOrdenado(cons, lenCons, aux); 
	fread(&reg, sizeof(personaUniversitaria), 1, doc);	
}
fclose(doc);

//se repite para noDoc y gra
//ahora abrimos el archivo nuevo
FILE *consolidado = fopen("consolidado.dat","wb+");

for(int i=0; i<lenCons; i++){
	write(&cons[i], sizeof(personaConsolidada),1, consolidado);
}
rewind(consolidado);	//vuevo al principio
fread(&aux, sizeof(personaConsolidada), 1, consolidado); //muestro el archivo
while(!feof(consolidado)){
	cout<<aux.per.legajo;
	cout<<aux.per.nombre;
	cout<<aux.per.claustro;
	fread(&aux, sizeof(personaConsolidada), 1, consolidado); 
}
fclose(consolidado);
