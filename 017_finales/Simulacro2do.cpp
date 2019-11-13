//Simulacro 2do Parcial

/*
1) (2 puntos) ​ ​ Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en la pila. Si se ingresa un asterisco se saca un
elemento de la pila. Imprimir la secuencia de caracteres que se sacaron de la
pila.
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/

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
			//tuve que castear el pop a char, pq me mostraba un entero en lugar del un char
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


//------------------------------------------------------
/*
Variante con cola, por mi.
Desarrollar un programa que reciba caracteres por teclado. Si se
ingresa una letra (A-Z) se inserta en una cola. Si se ingresa un asterisco se saca un
elemento de la cola. Imprimir la secuencia de caracteres que se sacaron de la
cola. 
Nota:​ El valor ascii de la A es 65 y el de la Z es 90.
*/

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
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
/*
2) (2 puntos) ​ Crear un procedimiento que dadas dos listas A y B, llene una lista C
con la unión (sin repetidos) de las listas A y B.
*/
//en la union, solo pongo 1 elemento de la interseccion

//Ejercicio resuelto por profe.
struct Nodo{
	int info;
	Nodo *sig;
};

void union(nodo *listaA, Nodo *listaB, Nodo *&listaC){
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
//------------------------------------------------------------------------------------
//mi resolución, usé dos veces insertar ordenado, no se si está bien.
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

/*
Variante por mi, en lugar de union, interseccion.
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
//Otra forma mas facil, es usar buscaEInsertaOrdenado

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
	insertarOrdenado(lista, reg.info);	//ORDENADO POR HORA
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

//Ahora vamos a guardar lo del archivo en la lista y sublista

// lista(se separa para poder manejar más facil. Asi en lista solo tengo dos campos: info y sig)
struct cliente{
	int nroCliente;
	float dineroGastado;
	NodoSublista *articulos;	//cabeza a una sublista
}

struct NodoLista{
	cliente info;
	NodoLista *sig;
}

//sublista
struct articulo{
	char art[30];
	int cantidad;
	float precio;
}

struct NodoSublista{
	artículo info;
	NodoSublista *sig;
}


FILE *arch = fopen("ventas.dat", "rb");
venta reg;

bool enc;
NodoLista *lista = NULL;

//declaro estructuras y punteros de tipo estructuras para guardar los nodos q me devuelva la funcion buscar
cliente infoLista;
NodoLista *buscado;

articulo infoArt;
NodoSublista *buscadoArt;

fread(&reg, sizeof(venta), 1, arch);
while(!feof(arch)){
	//buscamos si está el cliente, si es un nuevo articulo se inserta, si no se suma a la cantidad.
	//chequeamos si existe cliente. Hago de cuenta q no existe el cliente. Si no existe, me va retornar el puntero donde estaba. Si existe, lo inserta y me devuelve puntero de donde los inserta.
	
	//inicializo los parámetros de la estructura de cliente.
	infoLista.nroCliente = reg.nroCliente;	//asigno el cliente leido.
	infoLista.dineroGastado = 0;	//inicializo en cero, por ahora. 
	infoLista.articulos = NULL;		//inicializo sublista en vacio, por ahora.

	buscado = buscaEInserta(lista, infoLista, enc);	//buscar por numero de cliente
	
	//ahora tengo buscado, que es un cliente nuevo ó un cliente que ya existia, en cualquier caso, ahora si voy a completar los campos dineroGastado y la cabeza de la sublista.
	buscado->info.dineroGastado +=reg.cantidad * reg.precio;	//dinero gastado total, se acumula.
	
	//ahora vemos el tema de la sublista, nos fijamos si el articulo está.
	//primero, inicializo parámetros de la estructura de la sublista.
	strcpy(infoArt.art, reg.art);
	infoArt.cantidad = reg.cantidad;
	infoArt.precio = reg.precio;

	//Ahora buscamos si existe el articulo. Si existe, lo sumo. Si no existe, lo inserto. 
	//buscado es el puntero a cliente que teniamos de antes.
	//buscado->info.articulos, es la sublista de articulos que tiene cada cliente.
	buscadoArt = buscaEInserta(buscado->info.articulos, infoArt, enc); //busco por articulo	
	//si lo encontró, sumo la cantidad
	if(enc){
		buscandoArt->info.cantidad +=reg.cantidad;
	}
	//si no existia, buscaEInserta lo agrega automaticamente, ya que antes inicialicé infoArt
	fread(&reg, sizeof(venta), 1, arch);	//vuelvo a leer, para el siguiente registro.
}
fclose(arch);

//Ya terminé de cargar en memoria todo el archivo. Ahora procesamos.

//en total voy a guardar el total de dinero recaudado
float total =0;

//lista auxiliar, para no perder el comienzo de la lista original.
NodoLista  *auxLista = lista;

while(auxLista != NULL){
	total += auxLista->info.dineroGastado;	//sumo el dinero gastado de todos los clientes.
	//aprovecho, y muestro el nodo cliente, que tiene el nrocliente y su dinero gastado.
	cout<<"Numero de cliente "<<auxLista->info.nroCliente<<": "<<auxLista->info.dineroGastado;

	//Muestro del detalle de cada ciente. Para impimir esto, debemos mostrar sublista.
	cout<<"detalle"<<endl;
	//declaro una sublista auxiliar, para no perder la direccion original.
	NodoSublista *auxSub = auxLista->info.articulos;
	//recorro la sublista
	while(auxSub != NULL){
		cout<<auxSub->info.art<<" "<<auxSub->info.cantidad<<" "<<auxSub->info.precio<<" "<<auxSub->info.cantidad * auxSub->info.precio;
		//avanzamos
		auxSub = auxSub->sig;
	}
	//termine de recorrer los articulos, antes de ir a otro cliente teng que avanzar
	auxLista = auxLista->sig;
}
//una vez terminado de recorrer toda la lista, muestro el dinero total recaudado.
cout<<"total dinero Recaudado"<<total<<endl;
