//Simulacro 2do Parcial

/*
1) (2 puntos) ​ ​ Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en la pila. Si se ingresa un asterisco se saca un
elemento de la pila. Imprimir la secuencia de caracteres que se sacaron de la
pila.
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/

#include <iostream>
#include <string.h>
using namespace std;

struct Nodo{
		char info;
		Nodo *sig;		
	};

void push (Nodo* &pila, char valor);
int pop (Nodo* &pila);
void mostrar (Nodo* lista);

int main (){
	
	char car;
	Nodo *pila = NULL;
	do{
		cout<<"Ingresar caracteres: ";
		cin>>car;
		if('A'<=car && car<='Z'){
			push(pila, car);
		}
		if(car == '*'){
			cout<<pop(pila)<<endl;
		}
		
	} while (1);
	//mostrar(pila);
	return 0;
}
//----------------------------------------
void push (Nodo* &pila, char valor){
	Nodo* nuevo = new Nodo();
	nuevo->info = valor;
	nuevo->sig = pila;	

	pila = nuevo; 
}
//---------------------------------------
int pop (Nodo* &pila){
	Nodo* aux = pila;
	int v = aux->info;
	pila = aux->sig;
	delete aux;
	return v;
}
//---------------------------------------
void mostrar (Nodo* lista){ 
	while(lista != NULL){
		cout<<lista->info<<" -> ";
		lista = lista->sig;	
	}
}	

//profe
char var; 
Nodo *pila = NULL;
cou<<"Ingrese un caracter "<<endl;
cin>>var;
while(var != '.'){
	if(var >= 'A' && var <= 'Z'){
		push(pila, var)
	}
	if(var == '*'){

	}
}


//--------------------------------------------------------------
/*
2) (2 puntos) ​ Crear un procedimiento que dadas dos listas A y B, llene una lista C
con la unión (sin repetidos) de las listas A y B.
*/
//en la union, solo pongo 1 elemento de la interseccion
struct Nodo{
	int info;
	Nodo *sig;
};

vid union(nodo *listaA, Nodo *listaB, Nodo *&listaC){
	//Paso todo una lista, y de la segunda lista, paso los que no están
	
	Nodo *listaAaux = listaA;
	Nodo *listaBaux = listaB;
	bool enc; //esto no lo uso, pero está en el prototipo

	while(listaAaux != NULL){
		insertarOrdenado(listaC, listaAaux->info);
		listaAaux = listaAaux->sig;
	}

	while(listaBaux != NULL){
		buscaEInserta(listaC, listaBaux->info, enc);
		listaBaux = listaBaux->sig;
	}
}


//-----------------------------------------------------------------
/*
3) (3 puntos) ​ En el archivo “turnos20191031.dat” tenemos el listado de turnos de
un consultorio para un día en particular. De los turnos sabemos la hora (integer)
y el nombre del paciente. Ordenar la información contenida en el archivo por
hora y colocarlo en una cola para que puedan ser llamados.
*/

// NI PILAS NI COLAS SE RECORREN, SOLO LISTAS!!!!!!!!!!!!!!!1
struct turno{
	int hora;
	char nombre[50];
};

struct lista{
	turno info;
	Nodo *sig;
};

//la cola va tener los mismos tipos de datos de la lista
FILE *arch = fopen("turnos20191031","rb");
turno reg;

Nodo* lista = NULL;

fread(&reg, sizeof(turno), 1, arch);
while(!feof(arch)){
	//tengo que ponerlo en la lista ordenado.
	insertarOrdenado(lista, reg);	//ORDENADO POR HORA
	fread(&reg, sizeof(turno), 1, arch);
}

//ahora tengo mi lista ordenada, tengo q pasarla a una cola
//Creo la cola
Nodo *colaFte = NULL;
Nodo *colaFin = NULL;
//para no destruir la lista, creamos un auxiliar
Nodo *listaAux = lista;

while(listaAux != NULL){
	encolar(colaFte, colaFin, listaAux->info);
	listaAux = listaAux->sig;
}
fclose(arch);


//--------------------------------------------------------------------
/*
4) (3 puntos) ​ Se tiene un archivo “ventas.dat” que contiene los siguientes datos:
número de cliente, artículo comprado, cantidad comprada y precio unitario.
Con estos datos llenar una lista que debe contener número de cliente y dinero
gastado. A su vez cada nodo de esa lista, va a poseer una sublista de los
artículos comprados, junto con su cantidad comprada y precio unitario. Nota:
El precio unitario para cada artículo no varía. Si el artículo se repite por cada
cliente debe incrementarse su cantidad vendida.
Luego, mostrar un listado con la siguiente estructura:
Número de Cliente: $dineroGastado por el cliente
Detalle:
● Artículo cantidadDeUnidades precioUnitario total
Total de Dinero Recaudado: $dineroGastadoPorTodosLosClientes
*/

//esto tiene el archivo
struct venta{
	int nroCliente;
	char art[50];
	int cantidad;
	float precio;
}

//Ahora vamos por la lista y sublista

// lista
struct cliente{
	int nroCliente;
	float dineroGastado;
	NodoSublista *articulos;
}

struct NodoLista{
	cliente info;
	NodoLista *sig;
}

//sublista
struct NodoSublista{
	artículo info;
	NodoSublista *sig;
}

struct articulo{
	char art[30];
	int cantidad;
	float precio;
}

FILE *arch = fopen("ventas.dat", "rb");
venta reg;
bool enc;
NodoLista *lista = NULL;

cliente infoLista;
NodoLista *buscado;

NodoSublista *buscadoArt;

articulo infoArt;


fread(&reg, sizeof(venta), 1, arch);
while(!feof(arch)){
	//buscamos si está el cliente, si es un nuevo articulo se inserta y si no se suma a la cantidad
	//chequeamos si está el cliente. Hago de cuenta q no existe el cliente, si no existe, me va decir donde esta, Si existe, ya inserto
	infoLista.nroCliente = reg.nroCliente;
	infoLista.dineroGastado = 0;	//incialiazo en cero 
	infoLista.articulos = NULL;	

	buscado = buscaEInserta(lista, infoLista, enc);	//buscar por numero de cliente
	
	buscado->info.dineroGastado +=reg.cantidad * reg.precio;
	
	//nos fijamos si el articulo está.
	strcpy(infoArt.art, reg.art);
	infoArt.cantidad = reg.cantidad;
	infoArt.precio = reg.precio;

	//buscado es el cliente
	buscadoArt = buscaEInserta(buscado->info.articulos, infoArt, enc); //busco por articulo	
	//si lo encontró, sumo la cantidad
	if(enc){
		buscandoArt->info.cantidad +=reg.cantidad;
	}
fread(&reg, sizeof(venta), 1, arch);
}

float total =0;

//lista auxiliar
NodoLista  *auxLista = lista;

while(auxLista != NULL){
	total += auxLista->info.dineroGastado;
	cout<<"Numero de cliente "<<auxLista->info.nroCliente<<": "<<auxLista->info.dineroGastado;

		//para impimir esto, debemo mostrar sublista
	cout<<"detalle"<<endl;
	NodoSublista * auxSub = auxLista->info.articulos;
	//recorro la sublista
	while(auxSub != NULL){
		cout<<auxSub->info.art<<" "<<auxSub->info.cantidad<<" "<<auxSub->info.precio<<" "<<auxSub->info.cantidad * auxSub->info.precio;
		//avanzamos
		auxSub = auxSub->sig;
	}
	//termine de recorrer los aritulos, antes de ir a otro cliente teng que avanzar
	auxLista = auxLista->sig;
}

cout<<"total dinero Recaudado"<<total<<endl;
