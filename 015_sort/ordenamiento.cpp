#include <iostream>
using namespace std;

void agregar (int arr[], int n, int& len, int v);
void mostrar (int arr[],int len);
int menu();
void ordenarBurbuja (int arr[], int len);
void ordenarInsercion (int arr[], int len);
void ordenarSeleccion (int arr[], int len);

int main(int argc, char const *argv[]){
	int tamanio, len=0, valor, opcion;
	
	cout<<"Ingresar tamaño del array: ";
	cin>>tamanio;
	int array[tamanio];
	cout<<"---------------------------------"<<endl;

	cout<<"Ingrese valor 0 (cero) para finalizar."<<endl;
	for(int i=0; i<tamanio; i++){
		cout<<"Ingresar valor para array["<<i<<"]= ";
		cin>>valor;
		if(valor == 0)
			break;
		agregar(array, tamanio, len, valor);
	}	
	cout<<"---------------------------------"<<endl;
	cout<<"El array original es: "<<endl;
	mostrar(array,len);

	cout<<"---------------------------------"<<endl;
	opcion = menu();


	cout<<"---------------------------------"<<endl;
	switch(opcion){
		case 1:
			cout<<"Ordenado por burbujeo."<<endl;
			ordenarBurbuja(array, len);
			mostrar(array,len);
			break;
		case 2:
			cout<<"Ordenado por Inserción."<<endl;
			ordenarInsercion(array, len);
			mostrar(array,len);
			break;
		case 3:
			cout<<"Ordenado por Selección."<<endl;
			ordenarSeleccion(array, len);
			mostrar(array,len);
			break;
		default:
			cout<<"Error."<<endl;
			break;
	}

	return 0;
}
//-------------------------------------------
int menu (){
	int opt;
	cout<<"Elegir método de ordenamiento."<<endl;
	cout<<"[1]. Burbujeo."<<endl;
	cout<<"[2]. Inserción."<<endl;
	cout<<"[3]. Selección."<<endl;
	cin>>opt;
	return opt;
}
//-------------------------------------------
void agregar (int arr[], int n, int& len, int v){
	if (len == n)
		cout<<"Array lleno."<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}
//-------------------------------------------
void mostrar (int arr[],int len){
	for(int i=0; i<len; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return ;
}
//--------------------------------------------
/*
void ordenarBurbuja (int arr[], int len){
	int aux;
	for(int i=0; i<len-1; i++){
		for(int j=i+1; j<len;j++){
			if(arr[i]>arr[j]){
				// funcion de swap
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}
}
*/
//--------------------------------------------
void ordenarBurbuja (int arr[], int len){
	int aux;
	for(int i=0; i<len-1; i++){
		for(int j=0; j<len-1;j++){
			if(arr[j]>arr[j+1]){
				// funcion de swap
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}
}
//--------------------------------------------
void ordenarInsercion (int arr[], int len){
	int indice;
	for(int i=1; i<len; i++){
		indice=arr[i];
		for(int j=i-1; j>=0; j--){
			if(arr[j]>indice){
				arr[j+1]=arr[j];
				arr[j]=indice;
			}
		}
	}
}
//--------------------------------------------
void ordenarSeleccion (int arr[], int len){
	int menor=arr[0], menorPos, aux;

	for(int i=0; i<len-1; i++){
		menorPos=i;
		for(int j=i+1; j<len; j++){
			if(arr[menorPos] > arr[j]){
				menor = arr[j];
				menorPos = j;
			}
		}
		aux = arr[i];
		arr[i] = menor;
		arr[menorPos] = aux;
	}
}