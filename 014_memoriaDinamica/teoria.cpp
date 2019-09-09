//Memoria Dinamica


//PUNTERO: es una variable cuyo tipo de dato provee la capacidad de contener 
//una direccion de memoria.

int a = 10;
int *p = &a;	//declaracion del puntero
cout<<*p<<endl;	//imprimo el contenido donde apunta el puntero

//& (operador) Aplicado a una VARIABLE retorna su direccion de memoria

//* (operador) Aplicado a un puntero retorna su "contenido"


//NEW sirve para solicitar memoria en cualquier momento de la ejecucion del programa

//DELETE sirve para liberar memoria cuando ya no la necesitamos

int *p = new int(); //pido memoria del tipo int
*p = 10;	//
cout<< *p<<endl;
delete p;


//NODO: es una estructura AUTOREFERENCIADA que ademas de contener DATOS, posee 
//al menos un campo con la direccion de otro nodo del mismo tipo.

Struct Nodo{	//se hace referencia a si mismo: AUTOREFERENCIADA
	int info;
	Nodo* sig; 
}


//Operador Flecha -> : Nos sirve para acceder a los campos de la estructura referenciada (el nodo)

Nodo *p = new Nodo(); 
//ambos son lo mismo
(*p).info = 10;
p ->ino = 10;

//PILAS Y COLAS
