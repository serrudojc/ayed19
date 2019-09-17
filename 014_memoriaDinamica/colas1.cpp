//cola de banco, supermercado, etc, primero en entrar, primero en salir
/*
Ejercicio 1.
Dada una cola, desarrollar un procedimiento que elimine 2 nodos de la misma 
(indicar con un parámetro 'S'/'N' si ello fue‚ o no posible)
*/

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