#include <iostream>
#include <string.h>

using namespace std;

struct EST{
	int legajo;
	char apellido[30];
	float promedio;
};
EST veck1053[10];
EST veck1054[10];
EST vecC[20];
EST aux;

void inicializarVector(int arr[],int n); //como inicializar una estructura?
void agregar (EST arr[], int& len, int n, EST aux); //aux es un tipo de dato, NO UN VECTOR

int main (){
	
	int lenk1053=0, posk1053=0;
	int lenk1054=0, posk1054=0;
	int lenC=0;
	
//	inicializarVector(veck1053,10);
//	inicializarVector(veck1054,10);
//	inicializarVector(vecC,20);
//ingreso de datos para ambos cursos
	cout<<"Curso K1053: Ingrese un legajo(ordenado), apellido y promedio: ";

	cin>>aux.legajo;
	cin>>aux.apellido;
	cin>>aux.promedio;

	while(aux.legajo>0){	//ojo con agregar mas de 10 elemenos!!!
		agregar(veck1053,lenk1053,10,aux);

		cout<<"Curso K1053: Ingrese un legajo(ordenado), apellido y promedio: ";
		cin>>aux.legajo;
		cin>>aux.apellido;
		cin>>aux.promedio;
	}
//--------------------------------------------------------------------------
	cout<<"Curso K1054: Ingrese un legajo(ordenado), apellido y promedio: ";

	cin>>aux.legajo;
	cin>>aux.apellido;
	cin>>aux.promedio;

	while(aux.legajo>0){
		agregar(veck1054,lenk1054,10,aux);
		cout<<"Curso K1054: Ingrese un legajo(ordenado), apellido y promedio: ";
		cin>>aux.legajo;
		cin>>aux.apellido;
		cin>>aux.promedio;
	}

//apareo
	while(posk1053<lenk1053 && posk1054<lenk1054){
		if(veck1053[posk1053].legajo < veck1054[posk1054].legajo){
			agregar(vecC,lenC,20,veck1053[posk1053]);
			posk1053++;
		}else{
			agregar(vecC,lenC,20,veck1054[posk1054]);
			posk1054++;
		}
	}

	while(posk1053<lenk1053){
		agregar(vecC,lenC,20,veck1053[posk1053]);
		posk1053++;
	}

	while(posk1054<lenk1054){
		agregar(vecC,lenC,20,veck1053[posk1054]);
		posk1054++;
	}

//NO SE PUEDE cout<<VEC[i]<<endl; NOOO, NO SE PUEDE
	for(int i=0;i<lenC;i++){
		cout<<vecC[i].legajo<<endl;
		cout<<vecC[i].apellido<<endl;
		cout<<vecC[i].promedio<<endl;
		cout<<"anandansdlkanslka"<<endl;
	}
	return 0;
}

//-------------------------------------------------------
void inicializarVector(int arr[],int n){
	for (int i=0;i<n;i++)
		arr[i]=0;
	return;
}
//-------------------------------------------------------
void agregar (EST arr[], int& len, int n, EST aux){
	
	if (len==n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len].legajo=aux.legajo;
		strcpy(arr[len].apellido,aux.apellido); //no puedo hacer arr[len].apellido=aux.apellido
		arr[len].promedio=aux.promedio;
		len++;
	}
	return;
}
