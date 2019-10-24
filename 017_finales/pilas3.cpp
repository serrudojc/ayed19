#include <iostream>

using namespace std;

struct nodo {
 	int info;
    nodo* sig;
};
nodo*pila = NULL;

void push (nodo* &pila, char valor);
char pop ( nodo* &pila);

int main(){
    
    char letra;

    cout<<"Ingrese una letra"<<endl;
    cin>>letra;

    while(letra != '1'){
        push(pila, letra);
        
        cout<<"Ingrese otra letra"<<endl;
        cin>>letra;
    }

    while(pila != NULL){
        cout<<pop(pila)<<endl;
    }

}


void push (nodo* &pila, char valor){
 nodo* nuevo = new  nodo();
 nuevo -> info = valor;
 nuevo -> sig = pila;
  pila = nuevo;
}


char pop( nodo* &pila){
	char v = pila -> info;
	nodo* aux = pila;
	pila = pila -> sig;
	delete aux;
	return v;
}

//Vectores(arreglos) en lugar de pilas*********************************
char pila[100];
int posPila[99];

void pushPila(char pila[], char letra, int &posPila){
    pila[posPila] = letra;
    posPila--;
}

char popPila(char pila[],int &posPila){
    posPila++;
    return pila[posPila];
}

//Colas en lugar de pilas **********************************************

struct nodo2 {
    char info;
    nodo2*sig;
};

nodo2*colafrente1 = NULL;
nodo2*colafin1 = NULL;
nodo2*colafrente2 = NULL;
nodo2*colafin2 = NULL;
void encolar (nodo2* &colafte, nodo2* &colafin, char v);
char desencolar (nodo2* &colafte, nodo2* &colafin);

void pushColas(nodo2*colafrente1,nodo2*colafin1,nodo2*colafrente2,nodo2*colafin2,char letra){
    encolar(colafrente1,colafin1,letra);
    while(colafrente2 != NULL){
        encolar(colafrente1,colafin1,desencolar(colafrente2,colafrente2));
    }
    colafrente2 = colafrente1;
    colafrente1 = colafin1;
    colafrente1 = NULL;
    colafin1 = NULL;

}
char popColas(nodo2*colafrente2,nodo2*colafin2){
    return desencolar(colafrente2,colafin2);
}



void encolar (nodo2* &colafte, nodo2* &colafin, char v){
	nodo2* nuevo = new nodo2();
	nuevo -> info = v;
	nuevo -> sig = NULL;
	
	if (colafte == NULL){
		colafte = nuevo;
	}else{
		colafin -> sig = nuevo;
	}
	colafin = nuevo;
}

char desencolar (nodo2* &colafte, nodo2* &colafin){
	char v = colafte -> info;
	nodo2* aux = colafte;
	colafte = colafte -> sig;
	
	if ( colafte == NULL)
    {
		colafin = NULL;
    }
    
	delete aux;
	return v;	
}

//----------------------------------------------------------------
//copiado del pizarron
/*


//programa ppal
char letra;

cout<<"ingrese una letra"<<endl;
cin>>letra;
while(letra!=-1 ){
	//si hago esto, lo pongo en el vector
	push(pila, letra);

	cout<<"ingrese una letra"<<endl;
	cin>>letra;
}

//imprimir en orden inverso
while(pila != NULL){
	cout<<pop(pila)<<endl;
}


//array
char pila[100];
int  lenPila posPila = 99;

void push(char pila[], char letra, int &posPila){
	//imitar el funcionamiento de la pila.
	//el primero en entrar es el ultimo en salir
	pila[posPila] = letra;
	posPila--;
}

char pop(char pila[], int &posPila){
	//sumo uno, pq la posicion es la siguiente.
	posPila++;
	return pila[posPila];
}

//colas
//Hacemos dos. No alcanza con una sola
struct Nodo{
	char info;
	Nodo *sig;
};

Nodo *colaFte1 = NULL;
Nodo *colaFin1 = NULL;
Nodo *colaFte2 = NULL;
Nodo *colaFin2 = NULL;

void push(Nodo *colaFte1, Nodo *colaFin1, Nodo *colaFte2, Nodo *colaFin2, char letra){
	encolar(colaFte1, colaFin1, letra);

	//sacamos de una y encolamos en la otra
	while(colaFte2 != NULL){
		encolar(colaFte1, colaFin1, desencolar(colaFte2, colaFin2));
	}

	//switcheo
	colaFte2 = colaFte1;
	colaFin2 = colaFin1;
	//debo dejar uno libre
	colaFte1 = NULL;
	colaFin1 = NULL;
}

char pop(Nodo *colaFte2, Nodo *colaFin2){
	return desencolar(colaFte2, colaFin2);
}
*/