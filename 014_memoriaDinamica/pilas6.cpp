/*
Ejercicio Nro. 6:
Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos de
estudiantes y los imprima en orden inverso al de ingreso.
*/
struct Nodo
{	string apellido;
	Nodo* sgte;
	
};

void ordenInverso (){
	Nodo* pila = NULL;

	string apellido;
	cout<<"Ingrese un apellido"<<endl;
	cin>>apellido;
	while (apellido != 'x'){
		//guardo los apellidos, uso push
		push(pila, apellido);
		cout<<"Ingrese ....."<<endl;
		cin>>apellido;
	}
	//imprimo

	while(pila != NULL){
		cout<<pop(pila)<<endl;
	}
}