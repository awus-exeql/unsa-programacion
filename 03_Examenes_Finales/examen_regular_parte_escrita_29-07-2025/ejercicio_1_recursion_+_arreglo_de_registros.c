/*
Un Biologo que trabaja en una reserva natural de argentina, lleva una lista de
los animales que captura de la reserva para estudiarlos. A cada animal se le agrega
un rastreador satelital al devolverlos a su habitat. De cada animal lleva la siguiente
informacion: Codigo (Numerico), Nombre vulgar, Tipo (Ave, Mamifero, Reptil, Pez),
Peso (Numerico), Edad (Numerico).

Se requiere un programa que utilizando Recursividad y TD arreglo de registros permita,
ingresar la lista de N animales estudiados, posteriormente se ordenará la misma por
el campo Codigo utililizando el metodo QSort. Luego presentar un menu con las siguientes
opciones:
	a) Dada una edad ingresada por teclado, crear y mostrar una nueva lista con los animales
	que tienen la misma "Edad".
	b) Dado un Nombre vulgar informar cuantos animales de esta especie se han estudiado.
*/
#include <stdio.h>
#include <string.h>

#define Max_Cad 20
#define Max_List 30
typedef char TCad[Max_Cad];
typedef struct{
	int codigo,tipo,edad;
	float peso;
	TCad nombre;
}TAnimal;
typedef TAnimal TVec[Max_List];

// PROTOTIPOS
void LimpiaBuffer(char);
void LeeCad(TCad,int);
TAnimal GTAnimal(void);
void MostrarTAnimal(TAnimal);
void IngresoLista(TVec,int);
void MostrarLista(TVec,int);
void QSort(TVec,int,int);
void MismaEdad(TVec,int,int);
int CantxNombre(TVec,int,TCad);
int Opciones();
void Menu(TVec,int);

int main(void){
	TVec Anim;
	int n;
	printf("Cantidad de animales estudiados: ");
	scanf("%d",&n);
	IngresoLista(Anim,n);
	printf("\n[Aplicando ordenamiento QSort a la lista]\n");
	QSort(Anim,1,n);
	printf("\nLISTA ORDENADA POR CODIGO\n");
	MostrarLista(Anim,n);
	Menu(Anim,n);
	return 0;
}
void LimpiaBuffer(char c){
	if(c!='\n' && c!=EOF){
		c=getchar();
		LimpiaBuffer(c);
	}
}
void LeeCad(TCad C,int i){
	char c;
	c=getchar();
	if(c!='\n' && c!=EOF && i<Max_Cad-1){
		C[i]=c;
		LeeCad(C,i+1);
	}
	else{
		C[i]='\0';
		LimpiaBuffer(c);
	}
}
TAnimal GTAnimal(void){
	TAnimal G;
	printf("Codigo: ");
	scanf("%d",&G.codigo);
	LimpiaBuffer(getchar());
	printf("Nombre vulgar: ");
	LeeCad(G.nombre,0);
	printf("Tipo (1)ave (2)mamifero (3)reptil (4)pez: ");
	scanf("%d",&G.tipo);
	printf("Peso: ");
	scanf("%f",&G.peso);
	printf("Edad: ");
	scanf("%d",&G.edad);
	return G;
}
void MostrarTAnimal(TAnimal A){
	printf("\nCodigo: %d",A.codigo);
	printf("\nNombre vulgar: %s",A.nombre);
	switch(A.tipo){
	case 1: printf("\nTipo: Ave"); break;
	case 2: printf("\nTipo: Mamifero"); break;
	case 3: printf("\nTipo: Reptil"); break;
	case 4: printf("\nTipo: Pez"); break;
	}
	printf("\nPeso: %f",A.peso);
	printf("\nEdad: %d\n",A.edad);
}
void IngresoLista(TVec V,int N){
	if(N>0){
		IngresoLista(V,N-1);
		printf("\nAnimal [%d]\n",N);
		V[N]=GTAnimal();
	}
}
void MostrarLista(TVec V,int n){
	if(n>0){
		MostrarLista(V,n-1);
		printf("\n=> Animal [%d] <=",n);
		MostrarTAnimal(V[n]);
	}
}
void QSort(TVec V,int ini,int fin){
	int izq,der;
	TAnimal piv;
	if(ini<fin){
		piv=V[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der && V[der].codigo>piv.codigo)
				der--;
			if(izq<der){
				V[izq]=V[der];
				izq++;
			}
			while(izq<der && V[izq].codigo<piv.codigo)
			   izq++;
			if(izq<der){
				V[der]=V[izq];
				der--;
			}
		}
		V[der]=piv;
		QSort(V,ini,der-1);
		QSort(V,der+1,fin);
	}
}
void MismaEdad(TVec V,int N,int Edad){
	if(N>0){
		MismaEdad(V,N-1,Edad);
		if(V[N].edad==Edad){
			printf("\nAnimal en posicion [%d]\n",N);
			MostrarTAnimal(V[N]);
		}
	}
}
int CantxNombre(TVec V,int N,TCad Nombre){
	if(N>0){
		if(strcmp(V[N].nombre,Nombre)==0)
			return 1+CantxNombre(V,N-1,Nombre);
		else
			return CantxNombre(V,N-1,Nombre);
	}
	else
	   return 0;
}
int Opciones(){
	int opc;
	printf("\nMENU\n");
	printf("\n(1) Lista de animales con la misma edad");
	printf("\n(2) Cantidad de animales estudiados con el mismo nombre");
	printf("\n(0) Salir");
	printf("\nEleccion: ");
	scanf("%d",&opc);
	LimpiaBuffer(getchar());
	return opc;
}
void Menu(TVec V,int N){
	int opc,edad,cantxn;
	TCad nombre;
	opc=Opciones();
	if(opc){
		switch(opc){
		case 1:
			printf("\nEdad: ");
			scanf("%d",&edad);
			MismaEdad(V,N,edad);
			break;
		case 2:
			printf("\nNombre: ");
			LeeCad(nombre,0);
			cantxn=CantxNombre(V,N,nombre);
			printf("\nCantidad de animales estudiados con el mismo nombre vulgar: %d\n",cantxn);
			break;
		default: printf("\nOpcion invalida!!\n");break;
		}
		Menu(V,N);
	}
}
