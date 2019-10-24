#include <iostream>

using namespace std;

struct nodo {
 	char info;
    nodo* sig;
};

//VARIABLES DEL INPUT (Si se agregan mas en el arreglo, cambiar el tamaño.)
char arreglo[] = { '{', '(', '[', ']', ')', '}' };
int tamanio = 6;
nodo* pila = NULL;
 
//Prototipos de funciones
void push (nodo* &pila, char valor);
char pop ( nodo* &pila);
bool estaBalanceado(char arreglo[],int tamanio);

//Programa Principal
int main(){
    if(estaBalanceado(arreglo,tamanio) == true){
        cout<<"Esta Balanceado"<<endl;
    }else{
        cout<<"No esta Balanceado"<<endl;
    }
    return 0;
}

bool estaBalanceado (char arreglo[],int tamanio){

    bool balanceado = true;
    
    for(int i = 0;i<tamanio;i++){
            if(arreglo[i] == '{' || arreglo[i] == '[' || arreglo[i] == '(' ){
                push(pila,arreglo[i]);
            }else{
                char valorPila = pop(pila);
    
                switch (arreglo[i])
                {
                case '}':
                    /* code */
                    if(valorPila != '{'){
                        balanceado = false;
                    }
                    break;
                case ')':
                    /* code */
                    if(valorPila != '('){
                        balanceado = false;
                    }
                    break;
                case ']':
                /* code */
                if(valorPila != '['){
                    balanceado = false;
                }
                break;
                default:
                    break;
                }
            }
            if(!balanceado){
                break;
            }
       }

    if (balanceado){
        if(pila != NULL){
            balanceado = false;
        }
    }
    
    return balanceado;
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


//-------------------------------------------------------------------------------
//copiado de pizarron
/*

struct Nodo{
	char info;
	Nodo *sig;
};

bool estaBalanceado(char entrada[], int len){
	Nodo* pila = NULL;
	char aux;
	bool balanceado = true;

	for(int i=0; i<len; i++){

		if(entrada[i]=='[' || entrada[i]=='(' || entrada[i]=='{'){
			push(pila, entrada[i]);
		}else{
			aux = pop(pila);
			switch(aux){
				case '[':
				if(entrada[i] != ']'){
					balanceado = false;
				}
				break;

				case '(':
				if(entrada[i] != ')'){
					balanceado = false;
				}
				break;

				case '{':
				if(entrada[i] != '}'){
					balanceado = false;
				}
				break;
			}
		}
		if(!balanceado){
			break;
		}
	}
	//cheaqueo si quedo algo en la pila cuando termino todo. Si me queda algo en la pila no esta balanceado.
	if(balanceado && pila!= NULL){
		balanceado = false;
	}
	return balanceado;
}
*/