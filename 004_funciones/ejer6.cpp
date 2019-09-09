# include <iostream>
using namespace std;

void sumarHora (long h, long t, long &res);

int main (){
	long horacompleta,tiempocompleto,res=999999;

	cout<<"Ingresar hora (hhmmss)"<<endl;
	cin>>horacompleta;
	cout<<"Ingresar tiempo (hhmmss)"<<endl;
	cin>>tiempocompleto;
	cout<<endl<<"-----------------------"<<endl;
	
	sumarHora(horacompleta,tiempocompleto,res);
	
	cout<<"** hhmmss sumado retornado desde la función mediante &: "<<res<<" ***"<<endl;
	return 0;
}

void sumarHora (long h, long t, long &res){
	long segh,segt, sumaseg=0;
	long minh,mint, sumamin=0;
	long horh,hort, sumahor=0;
	int dia=0;

	segh=h%100; 
	minh=(h/100)%100; 
	horh=h/10000; 

	segt=t%100; 
	mint=(t/100)%100;	
	hort=t/10000;  

	sumaseg=sumaseg+segh+segt; 
	if (sumaseg>60){
		sumaseg=sumaseg-60; 
		sumamin=sumamin+1;  
	}

	sumamin=sumamin+minh+mint;
	if (sumamin>60){
		sumamin=sumamin-60;
		sumahor=sumahor+1;
	}

	sumahor=sumahor+horh+hort;
	while(sumahor>24){
		sumahor=sumahor-24;
		dia=dia+1;
	}

	if (dia!=0)
		cout<<"hubo cambio de dia: "<<dia<<" dias, ";
	cout<<sumahor<<" hs, "<<sumamin<<" min, "<<sumaseg<<" seg."<<endl<<endl;

	res=sumahor*10000+sumamin*100+sumaseg;
	
}