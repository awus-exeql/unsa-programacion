/*Ejercicio 2: Se tiene una lista de N numeros naturales sin repetidos, se desea;encontrar el menor de la
lista sabiendo que existe y es unico, ordenar la lista de menor a mayor, insertar un nuevo elemento
manteniendo el orden y las caracteri­sticas de la lista, para finalizar, mostrar los primos presentes en la
lista.*/
#include <stdio.h>
#define Max_List 30

typedef int TVec[Max_List];

// DECLARACION DE PROTOTIPOS
void CargarVector(TVec,int);
int DetMenor(TVec,int);
void Baraja(TVec,int);
void CargaUno(TVec,int*,int);
void MostrarLista(TVec,int);
int DetPrimo(int,int);
void MostrarPrimos(TVec,int);

int main(void) {
	TVec V;
	int n,men;
	printf("Tamaño de la lista:");
	scanf("%d",&n);
	CargarVector(V,n);
	men=DetMenor(V,n);
	printf("\nNUMERO MENOR DE LA LISTA = %d\n",men);
	printf("\nLISTA\n");
	MostrarLista(V,n);
	printf("\n\nAplicando Ordenamiento en la Lista...");
	printf("\nLISTA ORDENADA\n");
	Baraja(V,n);
	MostrarLista(V,n);
	MostrarPrimos(V,n);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("V[%d] = ",i);
		scanf("%d",&V[i]);
	}
}
int DetMenor(TVec V,int n){
	int men,i;
	men=V[1];
	for(i=2;i<=n;i++){
		if(V[i]<men)
			men=V[i];
	}
	return men;
}
void Baraja(TVec V,int n){
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
void CargaUno(TVec V,int* n,int Nuevo){
	int i;
	V[0]=Nuevo;
	i=*n;
	while(V[0]<V[i]){
		V[i+1]=V[i];
		i--;
	}
	V[i+1]=V[0];
}
void MostrarLista(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nV[%d] = %d",i,V[i]);
}
int DetPrimo(int n,int num){
	int PD;
	PD=2;
	while(PD<=num/2 && num%PD!=0)
		PD++;
	if(PD>num/2 && num!=1)
		return 1;
	else
		return 0;
}
void MostrarPrimos(TVec V,int n){
	int b,i;
	b=1;
	printf("\n\nNUMEROS PRIMOS PRESENTES EN LA LISTA\n");
	for(i=1;i<=n;i++){
		if(DetPrimo(n,V[i])){
			b=0;
			printf("\nV[%d] = %d",i,V[i]);
		}
	}
	if(b)
		printf("\nNo hay numeros primos presentes en la lista\n");
}
