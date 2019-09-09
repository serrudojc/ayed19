#include <iostream>
using namespace std;
#define LEN 4
void agregar (int arr[], int n, int& len, int v);	//ejercicio 1
void inicializarVector (int arr[],int n);			
void mostrar (int arr[],int len);					//ejercicio 2
//--------------------------------------------------------
int main (){
	int n, valor;

	cout<<"ingresar tamanio del vector"<<endl;
	cin>>n;

	int vec[n];   
	int len=LEN;
	mostrar (vec,len);

	inicializarVector (vec, n);
	mostrar (vec,len);

	cout<<"ingresar valores (0 para terminar)"<<endl;	
	cin>>valor;
	while (valor>0){
		agregar(vec,n,len,valor);
		cin>>valor;
	}
	
	mostrar (vec,len);
	return 0;
}
//---------------------------------------------------------
void inicializarVector (int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=0;
	return;
}
//---------------------------------------------------------
void agregar (int arr[], int n, int& len, int v){
	
	if (len==n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}
//---------------------------------------------------------
void mostrar (int arr[],int len){
	int i;
	for(i=0;i<len;i++)
		cout<<"posicion ["<<i<<"] valor "<<arr[i]<<endl;
	cout<<endl;
	return ;
}