

/*
Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en la pila. Si se ingresa un asterisco se saca un
elemento de la pila. Imprimir la secuencia de caracteres que se sacaron de la
pila. 
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/
/*
#include <iostream>
using namespace std;

struct Nodo{
	char info;
	Nodo *sig;
};

void push (Nodo* &pila, char valor);
int pop (Nodo* &pila);
void mostrar (Nodo* pila);

int main (){
	char caracter;
	Nodo *pila = NULL;
	do{
		cout<<"Ingresar caracter: ";
		cin>>caracter;
		if(caracter >= 'A' && caracter <= 'Z'){
			push(pila, caracter);
		}
		//mostrar(pila);
		if(caracter == '*'){
			cout<<(char)pop(pila)<<endl;
		}
		//mostrar(pila);
	} while (caracter != '0');
	return 0;
}

void push (Nodo* &pila, char valor){
	Nodo* nuevo = new Nodo();	
	nuevo->info = valor;
	nuevo->sig = pila;	
	pila = nuevo; 
}
//---------------------------------------
int pop (Nodo* &pila){
	Nodo* aux = pila;
	char v = aux->info;
	pila = aux->sig;
	delete aux;
	return v;
}
void mostrar (Nodo* lista){ 
	while(lista != NULL){
		cout<<lista->info<<" -> ";
		lista = lista->sig;		
	}
	cout<<endl;
}	
*/
//------------------------------------------------------
//------------------------------------------------------
/*
Variante con cola, por mi.
Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en una cola. Si se ingresa un asterisco se saca un
elemento de la cola. Imprimir la secuencia de caracteres que se sacaron de la
cola. 
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/
/*
#include <iostream>
using namespace std;

struct Nodo{
	char dato;
	Nodo *sig;
};

void encolar (Nodo* &colaFte, Nodo* &colaFin, char v);
int desencolar (Nodo* &colaFte, Nodo* &colaFin);
void mostrar (Nodo* lista);

int main (){
	Nodo *colaFte = NULL;
	Nodo *colaFin = NULL;

	char caracter;

	do{
		cout<<"ingrese caracter: ";
		cin>>caracter;

		if(caracter>='A' && caracter<='Z'){
			encolar(colaFte, colaFin, caracter);
		}
		if(caracter == '*'){
			cout<<(char)desencolar(colaFte, colaFin)<<endl;
		}
	} while (caracter != 0);
	return 0;
}

void encolar (Nodo* &colaFte, Nodo* &colaFin, char v){
	Nodo* nuevo = new Nodo();
	nuevo->dato = v;
	nuevo->sig = NULL;

	if(colaFte == NULL){
		colaFte = nuevo; 
	}else{
		colaFin->sig = nuevo; 
	}
	colaFin = nuevo;
}
//-----------------------------------------------
int desencolar (Nodo* &colaFte, Nodo* &colaFin){
	char v = colaFte->dato;	
	Nodo* aux = colaFte;
	colaFte = colaFte->sig;
	if(colaFte==NULL)
		colaFin=NULL;
	delete aux;
	return v;
}
//---------------------------------------
void mostrar (Nodo* lista){ 
	while(lista != NULL){
		cout<<lista->dato<<" -> ";
		lista = lista->sig;		
	}
	cout<<endl;
}
*/

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*
2) (2 puntos) ​ Crear un procedimiento que dadas dos listas A y B, llene una lista C
con la unión (sin repetidos) de las listas A y B
*/
/*
#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo *sig;
};

void unionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC);

int main(){
	return 0;
}

void unionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC){
	bool enc;
	int valor;
	Nodo *auxA = listaA;
	Nodo *auxB = listaB;

	while(auxA !=  NULL){
		valor = auxA->info;
		buscaEInsertaOrdenado(listaC, valor, enc);
		auxA = auxA->sig; 
	}


	while(auxB !=  NULL){
		valor = auxB->info;
		buscaEInsertaOrdenado(listaC, valor, enc);
		auxB = auxB->sig; 
	}
}
*/
/*
2) (2 puntos)Por MI. ​ Crear un procedimiento que dadas dos listas A y B, llene una lista C
con la unión interseccion de las listas A y B
*/

#include <iostream>
using namespace std;

struct Nodo{
	int info;
	Nodo *sig;
};

void interseccionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC);

int main(){
	return 0;
}

void interseccionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC){
	Nodo *buscado;
	Nodo* auxA = listaA;
	Nodo *auxB = listaB;

	while(auxB != NULL){
		buscado = buscar(auxA, auxB->info);
		if(buscado != NULL){
			insertarOrdenado(listaC, auxB->info);
		}	
		auxB = auxB->sig;
	}
}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
/*
3) (3 puntos) ​ En el archivo “turnos20191031.dat” tenemos el listado de turnos de
un consultorio para un día en particular. De los turnos sabemos la hora (integer)
y el nombre del paciente. Ordenar la información contenida en el archivo por
hora y colocarlo en una cola para que puedan ser llamados.
*/

//estructura del archivo turnos
struct turnos{
	int hora;
	char nombrePaciente[30];
};

FILE *fp = fopen("turnos.dat","rb");
turnos reg;

//nodo
struct Nodo{
	turnos info;
	Nodo *sig;
};

Nodo *lista = NULL;


fread(&reg, sizeof(turnos),1,fp);

while(!feof(fp)){
	insertarOrdenado(lista, reg.info);	//ordeno por hora
	fread(&reg, sizeof(turnos),1,fp);	
}

Nodo *colaFte = NULL;
Nodo *colaFin = NULL;
Nodo *listaAux = lista;

while(listaAux != NULL){
	encolar(colaFte, colaFin listaAux->info);
	listaAux = listaAux->sig;
}

fclose(fp);


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
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

//struct del dato del archivo
struct archivo{
	int nroClie;
	char articulo[30];
	int cantidadComprada;
	float precioUnitario;
};
//---------------------------
//lista
struct ventas{
	infoVentas info;
	Nodo *sig;
}
struct infoVentas{
	int nroClie;
	float dineroGastado;
	compra *compraClie = NULL;
}
//----------------------------
struct compra{
	infoCompra info;
	compra *sig;
}
struct infoCompra{
	char articulo[30];
	int cantidadComprada;
	float precioUnitario;
};
//----------------------------

FILE *fp = fopen("ventas.dat","rb");
archivo reg;

ventas *ventasXClie = NULL;
compra *compraXClie = NULL;

fread(&reg, sizeof(archivo), 1, fp);

ventas *buscado;
//primeo veo si ya existe un cliente
buscado = buscar(ventasXClie, reg.nroClie);

if(buscado != NULL){
	//existe el cliente
}else{
	//si no existe el cliente
	insertarOrdenado(ventasXClie, reg)
}

































