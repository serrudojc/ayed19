#include <iostream>
using namespace std;
# define SIZE 10

int insertarOrdenado (int arr[], int &len,int v);
void inicializarVectorManual (int arr[],int n);
void mostrar (int arr[],int len);
int buscar (int arr[], int len, int v);
void ordenar (int arr[],int len);

int main (void){
	int vec[SIZE],len,valor;

	cout<<"ingresar ocupacion del vector: "; //tengo que verificar no poner una posicion fuera del vector
	cin>>len;
	cout<<endl;
	inicializarVectorManual(vec,len);

	mostrar(vec, len);

	ordenar(vec,len);
	mostrar(vec, len);

	cout<<"Ingresar valor a insertar: ";
	cin>>valor;
	cout<<endl;

	if (len>=SIZE)
		cout<<"Vector lleno.No se puede agregar"<<endl;
	else
		insertarOrdenado(vec,len,valor);

	mostrar(vec,len);
	return 0;
}
//********************************************
void ordenar (int arr[],int len){
	int i,k,aux;
	for (i=0;i<len-1;i++){
		for(k=i+1;k<len;k++){
			if(arr[i]>arr[k]){
				aux=arr[i];
				arr[i]=arr[k];
				arr[k]=aux;
			}
		}
	}
}
//********************************************
int insertarOrdenado (int arr[], int &len,int v){//ojo, saqué var POS
	int muevo,pos, i=0;									//devolver INT posicion
	
	while (1){
		if (arr[i+1]>=v && arr[i]<=v){
			pos=arr[i];
			break;
		}
		i++;
	}

	muevo=len-pos;
	while (muevo){
		arr[muevo+pos]=arr[muevo+pos-1];
		muevo--;
	}
	arr[pos]=v;
	len++;
	return pos;
}

//***PROFE**************************************
/*
int insertarOrdenado (int arr[], int &len,int v){
	int i=0;
	while(i<len && arr[i]<=v)
		i++
	insertar(arr,len, v, i);
	return i;
}
*/
//********************************************
void inicializarVectorManual (int arr[],int n){
	
	cout<<"Ingresar "<<n<<" valores para llenar el vector: ";
	for (int i=0;i<n;i++)
		cin>>arr[i];
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
