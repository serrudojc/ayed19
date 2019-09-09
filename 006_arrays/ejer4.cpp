#include <iostream>	//Solo borro un elemento
using namespace std;
# define SIZE 10

void eliminar (int arr[], int &len, int pos);
void inicializarVector (int arr[],int n);
void mostrar (int arr[],int len);
int buscar (int arr[], int len, int v);

int main (void){
	int vec[SIZE],len,valor,posicion;

	inicializarVector(vec,SIZE);

	cout<<"ingresar ocupacion del vector: ";
	cin>>len;
	cout<<endl;

	mostrar(vec, len);

	cout<<"Ingresar valor a eliminar: ";
	cin>>valor;
	cout<<endl;

	posicion=buscar (vec,len,valor);
	if (posicion == -1)
		cout<<"No se encuentra ese valor."<<endl<<endl;
	else{
		eliminar(vec,len,posicion);
	}
	mostrar(vec,len);
	return 0;
}
//********************************************
void eliminar (int arr[], int &len, int pos){
	int i;
	for (i=pos;i<len;i++){
		arr[i]=arr[i+1];
	}
	len--;
}
//********************************************
void inicializarVector (int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=i;
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
int buscar (int arr[], int len, int v){
	int i;

	for(i=0;i<len;i++){
		if(arr[i]==v)
			return i;
	}
	return -1;
}
//********************************************