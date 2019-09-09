#include <iostream>
using namespace std;

int main (){
	int matriz[3][3];
	int i,j;
	
	for (i=0; i<3; i++){
		for(j=0; j<3; j++){
			cout<<"Ingresar valor para ["<<i+1<<"]["<<j+1<<"]: ";
			cin>>matriz[i][j];
		}
	}
	cout<<endl;

	for (i=0; i<3; i++){
		for(j=0; j<3; j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}	

	cout<<"traspuesta de la matriz: "<<endl;

	for (i=0; i<3; i++){
		for(j=0; j<3; j++){
			cout<<matriz[j][i]<<"\t";
		}
		cout<<endl;
	}	

	return 0;
}