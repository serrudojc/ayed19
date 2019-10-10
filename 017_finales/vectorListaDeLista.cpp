//ver grafico en carpeta
/*

	_________ 		lista de tickets
	|       |       _______     ______
	|       |----->|____|_|--->|____|_|
	|_______|			|
	|       |			|         _______     _______	
	|       |			|------->|_____|_|---|____|_|-->
	|       |						lista de items
	|       |
	|       |
	|_______|
	vecMes[12]

*/
//-------------------------------------estructuras---------------
//esto es lo que contiene el archivo, ordenado. No se repiten productos por ticket
struct venta{
	int mes;
	int ticket;
	char descProd[50];
	int cant;
	float pu;
}
//---------------------------------------------------------------
//estas esctructuras me definen la lista de items

struct NodoItem{
	item info;
	NodoItem *seg;
}

struct item{
	char descProd[50];
	int cant;
	float pu;
	float total;
}
//----------------------------------------------------------------
//estas estructuras me definen la lista de tickets
struct NodoTicket{
	ticket info;
	NodoTicket *sig;
}

struct ticket{
	int nroTicket;
	float montoTotalTicket;
	NodoItem *items;
}
//----------------------------------------------------------------
//ahora definimos el tipo de dato del vector
ventaMes vecMes[12];
struct ventaMes{
	int cantTickets;
	NodoTicket *tickets;
}
//--------------------------------------------------------
//EMPEZAMOS CON EL EJERCICIO
//abrimos el archivo y lo cargamos en memoria, para poder trabajar
FILE *v = fopen("ventas2018.dat","rb");
venta reg;

bool enc;
ticket ticketAInsertar;

NodoTicket *nodoBuscado;

item itemAInsertar;

fread(&reg, sizeof(venta), 1, v);
while(!feof(v)){
	//como se en q posicion del vector va? Tengo el mes. 
	//Tengo que hacer un buscaEInserta
	//el tipo de dato de la lista es 
	ticketAInsertar.nroTicket = reg.ticket;
	ticketAInsertar.montoTotalTicket = 0; //no sabemos si está, vamos a usar un buscaEInserta, lo seteamos en cero
	ticketAInsertar.items = NULL; //no lo se aun.

	nodoBuscado = buscaEInserta(vecMes[reg.mes-1].tickets, ticketAInsertar, enc);

	//si el ticket no estaba, tenemos que sumar la cantidad de ticket acumulada
	if(enc == false){
		vecMes[reg.mes-1].cantTickets++;
	} 
	//ahora inserto el item
	//como accedo a la lista de items? a traves de nodobuscado
	//voy a necesitar item itemAInsertar;

	strcpy(itemAInsertar.descProd, reg.descProd);
	itemAInsertar.cant = reg.cant;
	itemAInsertar.pu = reg.pu;
	itemAInsertar.total = reg.cant * reg.pu;

	//ya tenemos nuestro item, ahora podermos insertarlo
	insertar(nodoBuscado->info.items, itemAInsertar);
	
	//me falta actualizar el monto total del ticket
	nodoBuscado->info.montoTotalTicket+=itemAInsertar.total;
	fread(&reg, sizeof(venta), 1, v);
}
fclose(v);
//listo, cargué mi estructura

//-------------------------------------------------------------------------------------
//ahora tenemos que imprimir el listado. Sólo recorremos las estructuras.
//un vector lo recorro con un for

int len = 12;

NodoTicket *auxTicket = NULL;
NodoItem *auxItem = NULL;

for(int i=0; i<len; i++){
	cout<<"Mes "<<i+1;
	auxTicket = vecMes[i].tickets;
	//necesitamos un auxiliar para recorrer
	//NodoTicket *auxTicket = vecMes[i].tickets;	//declaraciones dentro de cosas iterativas = MAL. Se hce afuera
	while(auxTicket != NULL){
		cout<<auxTicket->info.nroTicket<<endl;
		//recorremos los items, ncesitamos un auxiliar
		auxItem = auxTicket->info.items;
		while(auxItem != NULL){
			cout<<auxItem->info.descProd<<" ";
			cout<<auxItem->info.cant" ";
			cout<<auxItem->info.pu<<" ";
			cout<<auxItem->info.total<<endl;
			auxItem = auxItem->sig;
		}
	cout<<auxTicket->info.montoTotalTicket<<endl;
	auxTicket = auxTicket->sig;
	}
}
//--------------------------------------------------------------------------------------
//promedio y ticket de mayor monto

int len = 12;

NodoTicket *auxTicket = NULL;
NodoItem *auxItem = NULL;


for(int i=0; i<len; i++){

	float max = 0;
	float min = 9999999;
	float totalTicketsXmes = 0;
	float auxMontoTotalTicket;

	int ticketMax, ticketMin;

	auxTicket = vecMes[i].tickets;

	while(auxTicket != NULL){
		
		auxMontoTotalTicket = auxTicket->info.montoTotalTicket;
		if(auxMontoTotalTicket > max){
			max = auxMontoTotalTicket;
			ticketMax = auxTicket->info.nroTicket;
		}
		if(auxMontoTotalTicket < min){
			min = auxMontoTotalTicket;
			ticketMin = auxTicket->info.nroTicket;
		}
		//ahora acumulamos
		totalTicketsXmes->auxTicket->sig;
		
		
		auxTicket = auxTicket->sig;
	}
	IMPRIMIR MAX, MIN, PROM(totalTicketsXmes/ vecMes[i].cantTickets; )

}

//----------------------------------------------------------------------------
//PAra cuando es anual:
//si es por el año, las variables y la impresion afuera del for. El resto es lo mismo
//-----------------------------------------------------------------------------

int mesMax; maxtickets = 0;

for(int i00; i<len; i++){
	if(vecMes[i].cantTickets > maxtickets){
		maxtickets = vecMes[i].cantTickets; 
		mesMax = i;
	}

}
cout<<"el mes con mas tickets fue"<<mesMax+1<<endl;

//-----------------------------------------------------------------------------