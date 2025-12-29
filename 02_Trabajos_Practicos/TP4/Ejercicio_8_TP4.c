/*Ejercicio 8: Dada una lista A de N numeros enteros, que puede contener numeros repetidos, calcular
el promedio de los numeros que se encuentran en posiciones impares del arreglo y crear otra lista B
conteniendo los elementos de A que sean mayores al promedio calculado. Mostrar ambas listas.*/
#include <stdio.h>
#define Max_List 30
typedef int TVec[Max_List];

//PROTOTIPOS
void CargarVector(TVec,int);
void MostrarVector(TVec,int);
int PromedioPosImpares(TVec,int);
void NuevaListaxCriterio(TVec,int,TVec,int*,int);

int main(void) {
	int n,m,prom;
	TVec V,A;
	printf("Cantidad de numeros enteros:");
	scanf("%d",&n);
	CargarVector(V,n);
	printf("\nCalculando promedio asignado...\n");
	prom=PromedioPosImpares(V,n);
	printf("\nEl promedio es: %d\n",prom);
	printf("\nGenerando nueva lista segun criterio asignado...\n");
	NuevaListaxCriterio(V,n,A,&m,prom);
	MostrarVector(A,m);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Numero en posicion [%d]: ",i);
		scanf("%d",&V[i]);
	}
}
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nNumero en posicion [%d]: %d",i,V[i]);
}
int PromedioPosImpares(TVec V,int n){
	int i,acu,cont;
	cont=0;
	acu=0;
	for(i=1;i<=n;i+=2){
		cont++;
		acu+=V[i];
	}
	if(cont)
		return acu/cont;
	else
		return 0;
}
void NuevaListaxCriterio(TVec V,int n,TVec A,int* m,int prom){
	int i;
	*m=0;
	for(i=1;i<=n;i++){
		if(V[i]>prom){
			(*m)++;
			A[*m]=V[i];
		}
	}
}
