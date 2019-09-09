#include <iostream>
using namespace std;

void agregar (int arr[], int n, int& len, int v);

int main (){

	int vec1[5], vec2[5], len1=0, len2=0, pos1=0,pos2=0;
	int vec3[10],len3=0,pos3=0;
	int v;
	
	cout<<"ingresar datos para primer vector.Termina con negativo: ";
	cin>>v;
	while (v>0 && len1<5){
		agregar (vec1, 5, len1, v);
		cout<<"ingresar datos para primer vector.Termina con negativo: ";
		cin>>v;
	}
//--------------------------------------------------------------------------
	cout<<endl;
	cout<<"ingresar datos para segundo vector.Termina con negativo: ";
	cin>>v;
	while (v>0 && len2<5){
		agregar (vec2, 5, len2, v);
		cout<<"ingresar datos para segundo vector.Termina con negativo: ";
		cin>>v;
	}	
//--------------------------------------------------------------------------
	while (pos1<len1 && pos2<len2){
		if (vec1[pos1]<vec2[pos2]){
			vec3[pos3]=vec1[pos1];
			pos1++;
		}else{
			vec3[pos3]=vec2[pos2];
			pos2++;
		}
		len3++;
		pos3++;
	}
//---------------------------------------------------------------------------
	while (pos1<len1){
		vec3[pos3]=vec1[pos1];
		pos1++;
		len3++;
		pos3++;	
	}	
	while (pos2<len2){
		vec3[pos3]=vec2[pos2];
		pos2++;
		len3++;
		pos3++;
	}
//-----------------------------------------------------------------------------
	for (int i=0;i<len3;i++){
		cout<<"vec3["<<i<<"]: "<<vec3[i]<<endl;
	}

	return 0;
}
//-----------------------------------------------------------------------------
void agregar (int arr[], int n, int& len, int v){
	
	if (len == n)
		cout<<"esta lleno"<<endl;
	else{
		arr[len]=v;
		len++;
	}
	return;
}