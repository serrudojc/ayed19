#include <iostream>
using namespace std;

void smarHora (long t, long h, long &res);
long separarHora (long horario);
long separarMinutos (long horario);
long separarSegundos (long horario);

int main(){
	long unahora;
	long otrahora;
	cout<<"ingrese una hora"<<endl;
	cin>>unaHora;
	cout<<"ingrese otra hora"<<endl;
	cin>>otraHora;

	sumarHora(unaHora,otraHora,sumaDeHoras);
	cout<<"la suma es"<<sumaDeHoras;
	return 0;
}

void smarHora (long t, long h, long &res){

	long th=separarHora(t);
	long hh=separarHora(h);

	long tm=separarMinutos(t);
	long hm=separarMinutos(h);

	long tm=separarSegundos(t);
	long hs=separarSegundos(h);
	
	long segundosFinales=ts+hs;
	long minutosFinales= tm+hm;
	long horasFinales=th+hm;

	if(segundosFinales>=60){
		segunosFinales-60;
		minutosFinales+1;
	}
	if(minutosFinales>=60){
	minutosFinales=minutosFinales-60;
	horasFinales++;
	}
	if(horasFinales>=24){
		horasFinales=horasFinales-24;
	}

	res=horasFinales*10000+minutosFinales*100+segundosFinales;
	return;

}


long separarHora (long horario){
	return horario/10000;
}

long separarMinutos (long horario){
	return (horario%10000)/100;
}

long separarSegundos (long horario){
	return (horario%100);
}

