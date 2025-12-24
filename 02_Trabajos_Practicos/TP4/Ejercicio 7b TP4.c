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
void OrdenamientoxBaraja(TVec,int);
int BusqBin(TVec,int,char);
void MostrarVector(TVec,int);

int main(void) {
	int m,p;
	char X;
	TVec A;
	printf("Cantidad de caracteres:");
	scanf("%d",&m);
	CargarVector(A,m);
	printf("\nAplicando ordenamiento a la lista...\n");
	OrdenamientoxBaraja(A,m);
	MostrarVector(A,m);
	printf("\n\nCaracter a buscar:");
	scanf(" %c",&X);
	printf("\nBuscando caracter en la lista...\n");
	p=BusqBin(A,m,X);
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
void OrdenamientoxBaraja(TVec V,int n){
	int i,j;
	for(i=2;i<=n;i++){
		V[0]=V[i];
		j=i-1;
		while(V[0]<V[j]){
			V[j+1]=V[j];
			j--;
		}
		V[j+1]=V[0];
	}
}
int BusqBin(TVec V,int n,char busq){
	int ini,fin,med;
	ini=1;
	fin=n;
	med=(ini+fin)/2;
	while(ini<=fin && V[med]!=busq){
		if(busq<V[med])
			fin=med-1;
		else
			ini=med+1;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		return med;
	else
		return 0;
}
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nCaracter en posicion [%d]: %c",i,V[i]);
}
