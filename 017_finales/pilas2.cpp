#include <iostream>

using namespace std;

struct nodo {
 	int info;
    nodo* sig;
};

//VARIABLES DEL INPUT (Si se agregan mas en el arreglo, cambiar el tamaño.)
char arreglo[] = { '5', '1', '2', '+', '4', '*', '+', '3', '-' };
int tamanio = 9;
nodo* pila = NULL;
 
//Prototipos de funciones
void push (nodo* &pila, int valor);
int pop ( nodo* &pila);
int calcularResultado(char arreglo[],int tamanio);


int main(){
    
    cout<<calcularResultado(arreglo,tamanio)<<endl;
    
    return 0;
}

int calcularResultado(char arreglo[],int tamanio){
    int aux;
    for(int i = 0; i < tamanio ; i++){
        switch (arreglo[i])
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            push(pila,arreglo[i]-'0'); // el numero esta en ascii entonces necesitamos restarle la posicion del 0 para obtener el numero real.
            break;
        case '+':
            push(pila, pop(pila)+pop(pila) );
            break;
        case '-':
            aux = pop(pila);
            push(pila, pop(pila)-aux );
            break;
        case '*':
            push(pila, pop(pila)*pop(pila) );
            break;
        case '/':
            aux = pop(pila);
            if(aux != 0){
                push(pila, pop(pila)/aux );
            }else{
                cout<<"Error en la division"<<endl;
            }
            break;
        default:
            break;
        }
    }
    return pop(pila);
}


void push (nodo* &pila, int valor){
 nodo* nuevo = new  nodo();
 nuevo -> info = valor;
 nuevo -> sig = pila;
  pila = nuevo;
}

int pop( nodo* &pila){
	int v = pila -> info;
	nodo* aux = pila;
	pila = pila -> sig;
	delete aux;
	return v;
}

//---------------------------------------------------------------
//copiado del pizaron
/*
struct Nodo{
	int info;
	Nodo *sig;
}

int calcularResultado(char exp[], int len){
	Nodo *pila = NULL;
	int aux;

	//tenemos len
	for(int i=0; i<len; i++){
		//para no usar muchos if
		switch(exp[i]){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				push(pila, exp[i]-'0');
				break;
			case '+':
				push(pila, pop(pila) + pop(pila));
				break;
			case '-':
				aux = pop(pila);
				push(pila, pop(pila) - aux);
				break;
			case '*':
				push(pila, pop(pila) * pop(pila));
				break;
			case '/':
				aux = pop(pila);
				if(aux != 0){
					push(pila, pop(pila) / aux);	
				}else{
					cout<<"Error division"<<endl;
				}
				
				break;
		}
	}
	return pop(pila);
}
*/