#include <stdio.h>

int main (){
	int n,i;
	

	printf("Ingrese tamaño del vector\n");
	scanf ("%d",&n);
	int vector[n];

	for (i=0; i<n; i++)
		vector[i]=10+i;

	for (i=0; i<n;i++)
	printf("vector [%d]= %d \n",i,vector[i]);

	return 0;
}