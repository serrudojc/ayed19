# include <iostream>
using namespace std;

double pow (double x, double y);

int main (){
	double exp, base;
	cout<<"Ingresar base y exponente:"<<endl;
	cin>>base>>exp;
	cout<<endl<<"potencia es: "<<pow(base,exp)<<endl;
	return 0;
}

double pow (double x, double y){
	double i=0, potencia=1;

	for (i=0;i<y;i++){
		potencia=x*potencia;
	}
	return potencia;
}

// como hago potencia de 2^2.5, por ejemplo??
