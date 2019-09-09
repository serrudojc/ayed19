//cola de banco, supermercado, etc, primero en entrar, primero en salir

char eliminarNodosCola(Nodo*  &colaFte, Nodo* &colaFin, int nodosABorrar){
	//while con dos condiciones, pq no se cuantas veces voy a iterar 
	int contador;

	while(colaFte != NULL && contador<nodosABorrar){
		desencolar (colaFte, colaFin);
		contador++;
	}
	if (contador == nodosABorrar){
		resultado = 's';
	}else{
		resultado = 'n';
	}


	return resultado;
}