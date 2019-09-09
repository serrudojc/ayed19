/*crear un PROCEDIMIENTO que dados dos vectores A y B (10 elementos max c/u), llene un vector C 
con la interseccion de ambos A y B. */

#include <iostream>
using namespace std;

void interseccion(int vecA[],int vecB[],int vecC[],int lenA,int lenB,int &lenC);

int main (){
//declaro vectores //los lleno con algo, no dice que estan ordenados.
	int A[10]={1,1,5,4,6,8};	//si tngo dos elementos iguales en un vector, que hago? los tengo en cuenta?
	int B[10]={1,5,9,6,85,5555,2,55};

//declaro el len de cada vector, depende de con cuantos valores llene c/u, en este caso:
	int lenA=6;
	int lenB=8;

	int C[20], lenC=0;

	interseccion(A,B,C,lenA,lenB,lenC);

	cout<<"interseccion: ";
	for (int i=0; i<lenC; i++)
		cout<<C[i]<<" ";
	cout<<endl;

	return 0;
}

//esto seria en si el ejercicio pedido, pero hize todo lo anterior para poder compilar.
void interseccion(int vecA[],int vecB[], int vecC[],int lenA,int lenB,int &lenC){
	int i,k;

	for(i=0; i<lenA; i++){
		for(k=0; k<lenB; k++){
			if (vecA[i]==vecB[k]){
				vecC[lenC]=vecA[i];
				lenC++;
			}
		}
	}
}