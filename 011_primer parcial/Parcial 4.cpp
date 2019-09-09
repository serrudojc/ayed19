struct alu {
	int leg;
	char nombre [50];
	int cod;
	float nota;
};

struct aluA{
	int leg;
	char mat [50];
	int cod;
};

FILE * a= fopen ("aprobados.dat", "wb");
FILE * n= fopen("notas.dat","rb");

alu reg;
aluA regA;

int legAnt;
float sumaNotasXEst;
float peorNotaXEst;

float promedioXEst;
float mejorPromedio =0;
int legmejorPromedio;
float peorNota =10;
int legPeorNota;

fread(&reg, sizeof(alu),1,n);

while (!feof (n)){
	legAnt= reg.leg;
	cantNotasXEst =0;
	sumaNotasXEst =0;
	peorNotaXEst = 999999;
	promedioXEst=0;

			
		while (!feof(n) && leg.Ant ==reg.leg){
			cantNotasXEst++;
			sumaNotasXEst += reg.nota;	
		
				if (reg.nota < peorNotaXEst){
					peorNotaXEst = reg.nota;
				}
				
				if (reg.nota >= 6){
					regA.leg = reg.leg;
					strcpy (regA.mat, reg.nombre);
					regA.cod = reg.cod;
					fwrite (&regA, sizeof(aluA),1,a);
				}
		
		fread(&reg, sizeof(alu),1,n);
		}	
	
promedio = sumaNotasXEst / CantNotasXEst;

cout << "El promedio del estudiante" << leg Ant << "es" << promedioXEst;

	if	(promedioXEst > mejorPromedio){
		mejorPromedio = promedioXEst;
		legMejorPromedio = legAnt;
	}	
	
	if (peorNotaXEst < peorNota) {
		peorNota = peorNotasXEst;
		legPeotNota = legAnt;
	}
	
}

cout << "El mejor prom es del est" << legMejorPromedio;
cout << "La peor nota es del est" << legPeorNota;

fclose (a);
fclose (n);

