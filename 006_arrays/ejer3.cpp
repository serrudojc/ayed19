#include <iostream>
using namespace std;
#define MAX 10
#define LEN 5 // OJO , que len varia segun la ocupacion del vector

int buscar (int arr[], int len, int v);

int main (void){
	int vec[MAX],valor,i,pos;

	for (i=0;i<MAX;i++)
		vec[i]=i;
	
	cout<<"Ingresar valor a buscar: "<<endl;
	cin>>valor;

	pos=buscar (vec,LEN,valor);
	if (pos!=-1)
		cout<<"posicion es: "<<pos<<endl;
	else
		cout<<"No se encuentra en el vector"<<endl;
	return 0;
}

int buscar (int arr[], int len, int v){
	int i;

	for(i=0;i<len;i++){
		if(arr[i]==v)
			return i;
	}
	return -1;
}
/*
//usando while
int buscar (int arr[],int len,int v){
	int i=0, pos;

	while (i<len && arr[i]!=v)
		i++

	if(i==len)
		pos=-1;
	else 
		return pos;
	}
//Usando for
int buscar (int arr[], int len, int v){
	int pos=-1;
	for(int i=0;i<len;i++){
		if(arr[i]==v){
			pos i;
			break;
		}
	}
	return pos;
}
*/
