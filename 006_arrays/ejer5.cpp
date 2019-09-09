#include <iostream>
using namespace std;
# define SIZE 10

void insertar (int arr[], int &len,int v, int pos);
void inicializarVector (int arr[],int n);
void mostrar (int arr[],int len);
int buscar (int arr[], int len, int v);

int main (void){
	int vec[SIZE],len,valor,posicion;

	inicializarVector(vec,SIZE);

	cout<<"ingresar ocupacion del vector: "; //tengo que verificar no poner una posicion fuera del vector
	cin>>len;
	cout<<endl;

	mostrar(vec, len);

	cout<<"Ingresar valor a insertar: ";
	cin>>valor;
	cout<<endl;

	cout<<"Ingresar posicion donde insertar: ";
	cin>>posicion;
	cout<<endl;

	if (len>=SIZE)
		cout<<"Vector lleno.No se puede agregar"<<endl;
	else{
		if (posicion<0 || posicion >len)
			cout<<"Posicion invalida."<<endl<<endl;
		else{
			insertar(vec,len,valor,posicion);
		}	
	}
	mostrar(vec,len);
	return 0;
}
//********************************************
void insertar (int arr[], int &len,int v, int pos){
	int muevo;
	
	muevo=len-pos;
	while (muevo){
		arr[muevo+pos]=arr[muevo+pos-1];
		muevo--;
	}
	arr[pos]=v;
	len++;
}

//***PROFE************************************
/*
void insertar (int arr[], int &len,int v, int pos){
	for(int i=len-1;i>=pos;i--)
		arr[i+1]=arr[i];
	arr[pos]=v;
	len++;
}
*/
//********************************************
void inicializarVector (int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=i+1;
	return;
}
//********************************************
void mostrar (int arr[],int len){
	int i;
	for(i=0;i<len;i++)
		cout<<"posicion ["<<i<<"] valor "<<arr[i]<<endl;
	cout<<endl;
	return ;
}
//********************************************
