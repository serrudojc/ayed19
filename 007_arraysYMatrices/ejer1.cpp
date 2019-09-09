#include <iostream>
using namespace std;

void pares (int arr[],int tam);
void mostrar (int arr[],int tam);

int main (){
	int n;

	cout<<"Ingresar tamaño de vector (menor a 30)"<<endl;
	cin>>n;

	int vec[n];

	pares(vec,n);
	mostrar(vec,n);

	return 0;
}

void pares (int arr[],int tam){
	arr[0]=0;
	for (int i=1; i<tam; i++)
		arr[i]=i*2;
}

void mostrar (int arr[],int tam){
	for (int i=0;i<tam;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}


/*profe

int n, len=0;
cout<<"ingresar n menor o igual a 30"<<endl;
cin>>n;

while (n>30){
	cout<<"ingresar n menor o igual a 30"<<endl;
	cin>>n;
}
for (int i=0;i<n;i++)
	agregar (vec, n, len, i*2+2);
mostrar();