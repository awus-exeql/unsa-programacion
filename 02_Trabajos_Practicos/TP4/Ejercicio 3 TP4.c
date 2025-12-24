/*Ejercicio 3: Se tiene una lista de caracteres que representa una frase conformada con consonantes,
vocales en minusculas y digitos, el ingreso de la lista se finalizara al ingresar el caracter "/". Se solicita
ingresar un caracter y buscarlo en la lista ingresada informando la primera posicion donde se encuentra,
borrar de la lista los digitos presentes y para finalizar ordenar la lista ascendentemente y mostrar la lista
resultante.*/
#include <stdio.h>
#define Max_List 30
typedef char TVec[Max_List];
// PROTOTIPOS
void CargarVector(TVec,int*);
int BusqSec(TVec,int,char);
void EliminarDigitos(TVec,int*);
void Baraja(TVec,int);
void MostrarVector(TVec,int);

int main(void) {
	TVec V;
	int n,p;
	char bus;
	CargarVector(V,&n);
	printf("\nCaracter buscado:");
	scanf(" %c",&bus);
	p=BusqSec(V,n,bus);
	if(p)
		printf("\nCaracter '%c' se encuentra en la posicion = %d\n",bus,p);
	else
		printf("\nCaracter '%c' no encontrado en la lista\n",bus);
	printf("\nEliminando digitos..\n");
	EliminarDigitos(V,&n);
	MostrarVector(V,n);
	printf("\n\nAplicando ordenamiento..\n");
	Baraja(V,n);
	MostrarVector(V,n);
	return 0;
}
void CargarVector(TVec V,int* n){
	char c;
	*n=0;
	do{
		(*n)++;
		printf("Caracter %d:",*n);
		scanf(" %c",&c);
		V[*n]=c;
	} while(c!='/');
	(*n)--;
}
int BusqSec(TVec V,int n,char bus){
	int i;
	i=1;
	while(V[i]!=bus && i<=n)
		i++;
	if(i>n)
		return 0;
	else
		return i;
}
void EliminarDigitos(TVec V,int* n){
	int i,j;
	i=1;
	while(i<=*n){
		if(V[i]>47 && V[i]<58){
			for(j=i;j<*n;j++)
				V[j]=V[j+1];
			(*n)--;
		}
		else
		   i++;
	}
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
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nCaracter en posicion [%d] = %c",i,V[i]);
}
