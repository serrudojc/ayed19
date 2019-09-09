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