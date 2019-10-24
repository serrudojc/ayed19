/*
Final 14/12/16
*/
#include <iostream>
#include <string.h>
#include <conio.h>
#include<iostream>
#include<cstdlib>
#include <stdio.h>

using namespace std;

// estructuras

//uso string pq la funcion del enunciado devuelve un string

struct conversacion{
	int idConversacion;
	char nombre[50]; 	//del grupo o " " si es una persona
	bool notificar;
	bool vistaPrevia;
};

struct Nodo{
	conversacion info;
	Nodo *sig;
};

//otra estructura de 200 contactos

struct Contactos{
	int idUsuario;
	string nombreContacto;
	bool bloqueado;
};

contacto vecContactos[200];	//vector de contactos
Nodo *conversaciones;	//lista de conversaciones

struct mensaje{
	char texto[100];
};

int buscarEnLista(Nodo *a, int d){
	return a;
	//Caja negra, devuelve la posicion del usuario si existe o sino -1.
    if(id){
        return id;
    }else{
        return -1;
    }
};

string NumeroTelefonicoUsuario(int id){
    //Caja Negra, devuelve el numero de telefono del usuario.
    return "telefono en formato string";
};

string VistaPrevia(mensaje msj){
    //Caja Negra, devuelve un preview del mensaje entero, lo achica.
    return "vista previa!";
};

void emitirNotificacion(string titulo, string desc){
    //Caja negra, muestra en pantalla la notificacion.
};


//-----------------------------------------------------------------

//el tipo Mensaje ya existe, supuestamente
//idUsuarioEmisor ya viene dado, supuesto del examen
void NotificarMensajeRecibido(Nodo *conversaciones, Contacto vecContactos[], int idConversacion, int idUsuarioEmisor, Mensaje mensaje){

	bool bloqueado;
	string nombreContactoAMostrar;

	//primero buscamos la conversacion
	//el enunciado nos asegura que la conversacion existe. No hay q chequear nada
	Nodo *convBuscada = buscarEnLista(conversaciones, idConversacion);

	//ahora buscamos el contacto.
	//enunciado dice que el contacto puede no estar
	//el contacto lo buscamos en el vector de contactos. 

	int pos = buscarEnVector(vecContactos, idUsuarioEmisor);	//devuelve -1 si no encuentra

	if(pos != -1){
		bloqueado = vecContactos[pos].bloqueado;
		nombreContactoAMostrar = vecContactos[pos].nombreContacto;
	}else{
		bloqueado = false;
		nombreContactoAMostrar = numeroTelefonicoUsuario(idUsuarioEmisor);	//funcion que ya viene dada.
	}

	//----------------------------------------------------------------/
	//a que usuarios voy a notificar, a todos?
	//la condicion para notificar : que no esté bloqueda y el bool de notificar
	if(!bloqueado && convBuscada->info.notificar){
		string titulo;
		string descripcion;
		//jugamos con el cuadrito
		if(convBuscada->info.nombre == ""){
			//conversacion directa
			//Con vista previa o sin vista previa?
			titulo = nombreContactoAMostrar;
			if(convBuscada->info.vistaPrevia){
				//si vistaPrevia es verdadera. Directa con vista previa
				descripcion = vistaPrevia(mensaje);	//funcion dada
			}else{	//Directa sin vista previa
				descripcion = "nuevo mensaje";
			}
		}else{	//grupal
			titulo = convBuscada->info.nombre;
			if(convBuscada->info.vistaPrevia){
				//grupal con vista previa
				//muestro nobmre del emisor y la vista previa del mensaje
				descripcion = nombreContactoAMostrar+" : "+vistaPrevia(mensaje);
			}else{
				//grupal sin vista previa
				descripcion = "nuevo mensaje de"+nombreContactoAMostrar;
			}
		}
		//sin importar si es grupal o directa
		emitirNotificacion(titulo, descripcion);
	}
}