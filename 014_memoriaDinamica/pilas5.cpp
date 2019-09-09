bool inversa(char letras[], int len){
	Nodo* pila = NULL;
	bool esInversa = true;
	//pasamos todo lo del vector de char a nuestra pila
	for (int i =0; i<len; i++){
		push(pila, letras[i]);
	}

	//necesitamos otra pila. Ver prueba de escritorio en carpeta.
	Nodo* pilaB = NULL;
	//sacamos hasta el puntito
	char c = '/0'; 
	while(c != '.' && pila != NULL){
		//sacamos del a pila y guardamos
		c = pop(pila);
		//cheqeuaos que sea distinto de punto
		if(c != '.'){
			push(pilaB, c);
		}
	}

	//aho8pila ra comparo, esto funciona si tienen las misma cantidad
	while(pila != NULL && pilaB != NULL && esInversa !=false){
		if(pop(pila) != pop(pilaB)){
			esInversa = false
		}
	}
	//pregunto si no eran iguales.
	if (pilaB != NULL){
		esInversa = false;
	}

	if (pila != NULL){
		esInversa = false;
	}
	return esInversa;
}