#include <iostream>
using namespace std;

void continuar ();  //no devuelve nada? algun valor de error?

int main (){
	continuar();
	return 0;
} 

void continuar(){
	cout<<"Presione una tecla para continuar"<<endl;
	cin.get(); /*con un enter sale*/
}