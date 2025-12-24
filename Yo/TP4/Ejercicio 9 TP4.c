/*Ejercicio 9: Dada una lista A de M numeros naturales, se solicita crear un vector P que contenga la
posicion de los elementos de A, para que la lista se recorra ordenada de menor a mayor. Usar el vector
P para determinar cuantos elementos de A se encuentran en la posicion correcta, de estar ordenado.*/
#include <stdio.h>
#define Max_List 30
typedef int TVec[Max_List];
// PROTOTIPOS
void CargarVector(TVec,int);
void MostrarVector(TVec,int);
void CargarVectordePosicion(TVec,int,TVec,int);
int PosCorrecta(TVec,int,TVec,int);

int main(void){
	TVec A,P;
	int m,pos;
	printf("Cantidad de numeros naturales: ");
	scanf("%d",&m);
	CargarVector(A,m);
	CargarVectordePosicion(A,m,P,m);
	printf("\nLISTA DE POSICIONES\n");
	MostrarVector(P,m);
	printf("\n\nDeterminando elementos en posicion correcta...\n");
	pos=PosCorrecta(A,m,P,m);
	printf("\nHay '%d' elementos de la lista en posicion correcta.\n",pos);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Numero natural en posicion [%d]: ",i);
		scanf("%d",&V[i]);
	}
}
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nNumero natural en posicion [%d]: %d",i,V[i]);
}
void CargarVectordePosicion(TVec V,int n,TVec P,int m){
	int i,j,cont;
	for(i=1;i<=n;i++)
		P[i]=0;
	for(i=1;i<=n;i++){
		cont=1;
		for(j=1;j<=n;j++){
			if(V[j]<V[i]&&j!=i)
				cont++;
		}
		P[i]=cont;
		for(j=1;j<i;j++){
			if(P[j]==P[i])
				P[i]++;
		}
	}
}
int PosCorrecta(TVec V,int n,TVec P,int m){
	int cont,i;
	cont=0;
	for(i=1;i<=n;i++){
		if(i==P[i])
			cont++;
	}
	return cont;
}
