/*Ejercicio 7: Dada una lista A de M caracteres alfanumericos todos distintos y un caracter X ingresado
por teclado, se solicita informar si dicho caracter se encuentra en la lista A ingresada y en cual
posicion. Considerar los siguientes casos:
a) La lista A no esta ordenada.
b) Ordenar la lista A, previamente a determinar la posicion de los elementos.*/
#include <stdio.h>
#define Max_List 30
typedef char TVec[Max_List];
// PROTOTIPOS
void CargarVector(TVec,int);
int BusqSec(TVec,int,char);

int main(void) {
	int m,p;
	char X;
	TVec A;
	printf("Cantidad de caracteres:");
	scanf("%d",&m);
	CargarVector(A,m);
	printf("\nCaracter a buscar:");
	scanf(" %c",&X);
	printf("\nBuscando caracter en la lista...\n");
	p=BusqSec(A,m,X);
	if(p)
		printf("\nEl caracter '%c' se encuentra en la posicion:[%d]",X,p);
	else
		printf("\nCaracter '%c' no encontrado en la lista.",X);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Caracter en posicion [%d]: ",i);
		scanf(" %c",&V[i]);
	}
}
int BusqSec(TVec V,int n,char busq){ // Si no se encuentra en la lista retorna 0
	V[0]=busq;
	while(V[0]!=V[n])
		n--;
	return n;
}
