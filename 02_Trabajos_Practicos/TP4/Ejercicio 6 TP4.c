/*Ejercicio 6: Dada una lista A de M caracteres alfanumericos en minusculas, se solicita ingresarla y
continuacion, utilizando un menu de opciones, permitir:
a) Insertar un nuevo caracter en A, en la posicion P, la cual es ingresada por teclado.
b) Eliminar el elemento anterior al primer caracter de tipo vocal de la lista
c) Cambiar los caracteres que representan a las vocales (a, e, i, o, u), presentes en el arreglo A por
su equivalente en mayusculas (A, E, I, O, U).
d) Mostrar el vector A.*/

#include <stdio.h>
#define Max_List 30
typedef char TVec[Max_List];
// PROTOTIPOS
void CargarVector(TVec,int);
void InsertarElementoxPos(TVec,int,int);
void EliminarUnoxVocal(TVec,int*);
void VocalesenMayus(TVec,int);
void MostrarVector(TVec,int);

int main(void){
	TVec A;
	int m,p;
	printf("Cantidad de caracteres:");
	scanf("%d",&m);
	CargarVector(A,m);
	printf("\nINSERTAR ELEMENTO POR POSICION\n");
	printf("\nPosicion: ");
	scanf("%d",&p);
	InsertarElementoxPos(A,m,p);
	MostrarVector(A,m);
	printf("\n\nEliminando caracter anterior a la primer vocal...\n");
	EliminarUnoxVocal(A,&m);
	MostrarVector(A,m);
	printf("\n\nCambiando vocales minusculas por mayusculas...\n");
	VocalesenMayus(A,m);
	MostrarVector(A,m);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Caracter en posicion [%d]:",i);
		scanf(" %c",&V[i]);
	}
}
void InsertarElementoxPos(TVec V,int n,int pos){
	if(pos>=1&&pos<=n){
		printf("\nCaracter en posicion [%d]: %c",pos,V[pos]);
		printf("\nNuevo valor: ");
		scanf(" %c",&V[pos]);
	}
	else
	   printf("\nPosicion invalida\n");
}
void EliminarUnoxVocal(TVec V,int* n){
	int found,i,j;
	found=0;
	i=1;
	while(i<=*n && !found){
		if(V[i]=='a'||V[i]=='e'||V[i]=='i'||V[i]=='o'||V[i]=='u')
			found=1;
		else
			i++;
	}
	if(i<=*n && i>1){
		for(j=i-1;j<*n;j++)
			V[j]=V[j+1];
		(*n)--;
	}
}
void VocalesenMayus(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		switch(V[i]){
		case 'a':
			V[i]='A';
			break;
		case 'e':
			V[i]='E';
			break;
		case 'i':
			V[i]='I';
			break;
		case 'o':
			V[i]='O';
			break;
		case 'u':
			V[i]='U';
			break;
		}
	}
}
void MostrarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("\nCaracter en posicion [%d]: %c",i,V[i]);
}
