#include <iostream>
using namespace std;

void inicializar(int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=0;
	return;
}
//***********************************************************
/* Agrega el valor v al final del array arr[] e incrementa su longitud len
Entrada:
	arr:	vector donde voy agregar un elemento
	n:		cantidad maxima de elementos del vector
	len:	cantidad de elementos ocupados del vector
	v:		valor a agregar en el vector
*/
void agregar (int arr[], int n, int& len, int v){
	
	if (len == n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}
//***********************************************************
// recorre el vector arr mostrando el valor de cada elemento
void mostrar (int arr[],int len){
	for(int i=0; i<len; i++)
		cout<<"posicion ["<<i<<"] valor "<<arr[i]<<endl<<endl;
	return ;
}
//***********************************************************
/* Busca en el arr si existe o no el elemento v. 
	v: valor a buscar en el vector
Salida:
	posición de v ó -1 si no hay valor.
*/
//usando while
int buscar (int arr[],int len,int v){
	int i=0, pos;

	while (i<len && arr[i]!=v)
		i++

	if(i == len)
		pos=-1;
	else 
		return pos;
}
//Usando for
int buscar (int arr[], int len, int v){
	int pos=-1;
	for(int i=0; i<len; i++){
		if(arr[i] == v){
			pos i;
			break;
		}
	}
	return pos;
}
//***********************************************************
/* 4 Elimina valor que se encuentra en la posicion pos del arr, desplazando 
al i-enesimo elemento hacia la posicion i-1, para todo valor del i>pos y i<len.
Entrada:
	pos:	posicion donde se va eliminar el valor
*/
void eliminar (int arr[], int &len, int pos){
	for (int i=pos ;i<len-1; i++){
		arr[i]=arr[i+1];
	}
	len--;
}
//***********************************************************
/* 5 Inserta v en la posicion del arr, desplazando al i-enesimo elemento 
hacia la posicion i+1 para todo valor de i que verifique i>=pos e i<len
*/
void insertar (int arr[], int &len,int v, int pos){
	for(int i=len-1; i>=pos; i--)
		arr[i+1]=arr[i];
	arr[pos]=v;
	len++;
}
//***********************************************************
/* 6 Inserta el valor v en el arr en la posicion que corresponda segun el criterio de 
precedencia de los enteros. El array debe estar ordenado o vacio.
Salida:
	posicion donde se insertó el valor.
*/
int insertarOrdenado (int arr[], int &len,int v){
	int i=0;
	while(i<len && arr[i]<=v)
		i++
	insertar(arr,len, v, i);
	return i;
}
//***********************************************************
/* Busca el valor v en el arr, si lo encuentra asigna true a enc y retorna la 
posicion de v. Si no, asigna false a enc, inserta v en arr respetando el orden 
de los enteros y retorna la posicion en la que se ubicó-
Entrada:
	enc: 	indica si el valor se encontró en el vector.
Salida:
	posicion donde está o se insertó
*/
int buscaEInserta (int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr, len,v);
	if (pos != -1)
		enc=true;
	else{
		enc=false;
		pos=insertarOrdenado (arr, len, v);
	}
	return pos;
}