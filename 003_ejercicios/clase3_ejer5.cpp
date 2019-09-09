#include <iostream>

using namespace std;

float fSueldo;
int cant1=0, cant2=0, cant3=0, cant4=0;

int main (){
	cout<<"Ingresar sueldo."<<endl;
	cin>>fSueldo;
	while(fSueldo!=0){
		if(fSueldo<2000)
			cant1=cant1+1;
		else{
			if(fSueldo>=2000 && fSueldo<3000)
				cant2=cant2+1;
			else{
				if(fSueldo>=3000 && fSueldo<5000)
					cant3=cant3+1;
				else
					cant4=cant4+1;
				}
			}
		cout<<"Ingresar sueldo."<<endl;
		cin>>fSueldo;
	}
	cout<<"Cantidad de empleados que ganan menos de $2000: "<<cant1<<endl;
	cout<<"Cantidad de empleados que ganan $2000 o menos de $3000: "<<cant2<<endl;
	cout<<"Cantidad de empleados que ganan $3000 o menos de $4000: "<<cant3<<endl;
	cout<<"Cantidad de empleados que ganan mas de $5000: "<<cant4<<endl;
	return 0;
}

//ver negativos