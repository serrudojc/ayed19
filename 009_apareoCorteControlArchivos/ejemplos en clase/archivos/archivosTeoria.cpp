/*
Archivos Binarios

Esta formado por un conjunto de registros. Los registros tiene un tipo de dato casi siempre va ser Struct

archivo.dat (termina con EOF)

*/

//estructura auxiliar que me sirve para "volcar" los datos del archivo
struct Est{
	int leg;
	char apellido[30];
};
Est reg;


//abrir archivo. Si no existe, lo crea.
FILE *arch = fopen("ruta del archivo","forma de apertura")
/*
forma de apertura puede ser:
rb = lectura
wb = escritura
rb+ = lectura+escritura
wb+ = escritura+lectura
*/

//para leer
fread (&reg, sizeof(tipoDeDato), 1, arch);

//para escribir
fwrite (&reg, sizeof(tipoDeDato), 1, arch);

// una vez que terminé de pocesar el archivo SE CIERRA
fclose (arch);

//fin de archivo. Puedo usarlo cuando quiero saber si terminó un archivo:
feof(arch) //si es verdadero, es pq terminó el archivo

//DATO: recorrer un archivo es costoso (acceso secuencial), por eso se trata de
//recorrerlo UNA SOLA VEZ

//para volver al principio del archivo
reset(arch);//?????????revisar esta funcion
rewind (arch);

//procesado de un archivo

Est reg;
FILE *archivo = fopen ("estudiantes.dat","rb");
fread(&reg, sizeof(Est),1,archivo);	//leo primera vez
while (!feof(archivo)){
	//PROCESO, por ejemplo
	cout<<reg.apellido<<endl;
	fread (&ref, sizeof(Est),1,archivo);	//tengo que volver a leer
}
fclose (archivo);	//SIEMPRE CERRARLO UNA VEZ TERMINADO DE TRABAJAR CON EL ARCHIVO
