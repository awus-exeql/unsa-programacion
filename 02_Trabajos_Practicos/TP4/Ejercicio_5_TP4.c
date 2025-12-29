/*Ejercicio 5: Generar aleatoriamente una lista A de tamaño N, que simula notas de un examen parcial,
entre 0 y 100. A continuacion, determinar la/las notas modales (las que mas se repiten).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max_List 30
typedef int TVec[Max_List];
// PROTOTIPOS DE MODULOS
void CargarVector(TVec,int);
void MostrarVector(TVec,int);
int DetMayRepeticion(TVec,int);
void MostrarRepetidos(TVec,int,int);

int main(void){
	int n,rep;
	TVec A;
	srand(time(NULL));
	printf("Cantidad de notas:");
	scanf("%d",&n);
	CargarVector(A,n);
	MostrarVector(A,n);
	rep=DetMayRepeticion(A,n);
	printf("\n\nValor de la mayor repeticion: %d\n",rep);
	printf("\nMostrando el/los mas repetido/s de las notas\n");
	MostrarRepetidos(A,n,rep);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		V[i]=(rand()%(101));
}
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nNota en posicion [%d]: %d",i,V[i]);
}
int DetMayRepeticion(TVec V,int n){
	int i,j,may,frec;
	may=0;
	for(i=1;i<=n;i++){
		V[0]=V[i];
		j=i-1;
		while(V[0]!=V[j])
			j--;
		if(j==0){
			frec=1;
			for(j=i+1;j<=n;j++){
				if(V[j]==V[0])
					frec++;
			}
			if(may>0){
				if(frec>may)
					may=frec;
			}
			else
			   may=frec;
		}
	}
	return may;
}
void MostrarRepetidos(TVec V,int n,int F){
	int i,j,frec;
	for(i=1;i<=n;i++){
		V[0]=V[i];
		j=i-1;
		while(V[0]!=V[j])
			j--;
		if(j==0){
			frec=1;
			for(j=i+1;j<=n;j++){
				if(V[j]==V[0])
					frec++;
			}
			if(frec==F)
				printf("\nNota en posicion [%d]: %d",i,V[i]);
		}
	}
}
