/*
Ejercicio Nro. 3:
Dadas dos colas COLA y COLB, desarrollar un procedimiento que genere una única cola
COLC a partir de ellas. (Primero los nodos de COLA y luego los de COLB).
*/

void generar3ra(Nodo* &colaAFte, Nodo* &colaAFin, 
				Nodo* &colaBFte, Nodo* &colaBFin,
				Nodo* &colaCFte, Nodo* &colaCFin){

		while(colaAFte != NULL){
			encolar(colaCFte, colaCFin, desencolar(colaAFte, colaAFin));
		}
		while(colaBFte != NULL){
			encolar(colaCFte, colaCFin, desencolar(colaBFte, colaBFin));
		}
		return;
}