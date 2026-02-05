#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define Max_Cad 30

typedef char tCad[Max_Cad];
typedef struct{
	int dato;
	tCad otrodato;
}tReg;

typedef struct nodo{
	tReg registro;
	struct nodo* sig;
}tNodo;
typedef tNodo* tPtr;

// DECLARACION DE PROTOTIPOS
void LimpiaBuffer(char);
void LeeCad(tCad,int);
tReg GeneratReg();
void MostrartReg(tReg);
tReg GeneraCopiatReg(tReg);
tPtr CrearNodo();
tPtr CrearNodoxCond();
tPtr GeneraCopiatPtr(tPtr);
void CargaxCabeza(tPtr*,tPtr);
void CargaxCola(tPtr*,tPtr);
void CargaxOrden(tPtr*,tPtr);
void CargaListaIncondicional(tPtr*,int); // Dudo de que se utilicen estos modulos
void CargaListaCondicional(tPtr*,int*); // De carga
tPtr BusquedaxDato(tPtr,int);
void EliminarNodoxDato(tPtr*,int);
void ModificarNodoxDato(tPtr*,int);
tPtr GenerarNuevaListaxDato(tPtr,int);
void DepurarListaxDato(tPtr*,int);
void EliminarRepetidosxDato(tPtr*);
void MostrarLista(tPtr);

int main(void) {
	tPtr L;
	int n;
	CargaListaCondicional(&L,&n);
	MostrarLista(L);
	return 0;
}
void LimpiaBuffer(char c){
	while(c!='\n'&&c!=EOF)
		c=getchar();
}
void LeeCad(tCad C,int N){
	int i;
	char c;
	i=0;
	c=getchar();
	while(c!='\n'&&c!=EOF&&i<N-1){
		C[i]=c;
		i++;
		c=getchar();
	}
	C[i]='\0';
	LimpiaBuffer(c);
}
tReg GeneratReg(){
	tReg G;
	printf("dato: ");
	scanf("%d",&G.dato);
	LimpiaBuffer(getchar());
	printf("otro dato: ");
	LeeCad(G.otrodato,Max_Cad);
	return G;
}
void MostrartReg(tReg R){
	printf("dato: %d",R.dato);
	printf("otro dato: %s",R.otrodato);
}
tReg GeneraCopiatReg(tReg R){
	tReg Copia;
	Copia.dato=R.dato;
	strcpy(Copia.otrodato,R.otrodato);
	return Copia;
}
tPtr CrearNodo(){
	tPtr Nuevo = (tPtr)malloc(sizeof(tNodo));
	Nuevo->registro=GeneratReg();
	Nuevo->sig=NULL;
	return Nuevo;
}
tPtr CrearNodoxCond(){
	tPtr Nuevo = (tPtr)malloc(sizeof(tNodo));
	if(Nuevo!=NULL){
		Nuevo->registro=GeneratReg();
		Nuevo->sig=NULL;
	}
	else
	   printf("\nError!, memoria llena");
	return Nuevo;
}
tPtr GeneraCopiaNodo(tPtr N){
	tPtr Copia = NULL;
	if(N!=NULL){
		Copia = (tPtr)malloc(sizeof(tNodo));
		if(Copia!=NULL){
			Copia->registro=GeneraCopiatReg(N->registro);
			Copia->sig=NULL;
		}
		else
		   printf("\nError!, memoria llena");
	}
	return Copia;
}
void CargaxCabeza(tPtr* ini,tPtr Nuevo){
	if(*ini==NULL)
		*ini=Nuevo;
	else{
		Nuevo->sig=*ini;
		*ini=Nuevo;
	}
}
void CargaxCola(tPtr* ini,tPtr Nuevo){
	tPtr act = NULL;
	if(*ini==NULL)
		*ini=Nuevo;
	else{
		act=*ini;
		while(act->sig!=NULL)
			act=act->sig;
		act->sig=Nuevo;
	}
}
void CargaxOrden(tPtr* ini,tPtr Nuevo){
	tPtr act,ant;
	act=*ini;
	ant=NULL;
	while(act!=NULL && act->registro.dato<Nuevo->registro.dato){
		ant=act;
		act=act->sig;
	}
	if(ant==NULL){
		Nuevo->sig=*ini;
		*ini=Nuevo;
	}
	else{
		Nuevo->sig=act;
		ant->sig=Nuevo;
	}
}
void CargaListaIncondicional(tPtr* L,int n){
	int i;
	tPtr Aux = NULL;
	for(i=1;i<=n;i++){
		Aux=CrearNodoxCond();
		if(Aux!=NULL){
			// Acá se implementa cualquier carga de lista que hicimos anteriormente.
			// Por ejemplo, el CargaxOrden.
			CargaxOrden(L,Aux);
		}
	}
}
void CargaListaCondicional(tPtr* L,int* n){
	int seguir;
	tPtr Aux = NULL;
	seguir=1;
	*n=0;
	do{
		if(seguir==1){
			Aux=CrearNodoxCond();
			if(Aux!=NULL){
				(*n)++;
				CargaxOrden(L,Aux);
			}
		}
		else
		   if(seguir!=0)
				printf("\nOpcion invalida\n");
		printf("(1) Cargar,(0) Finalizar:");
		scanf("%d",&seguir);
		__fpurge(stdin);
	}while(seguir);
}
tPtr BusquedaxDato(tPtr L,int Dato){
	while(L!=NULL && L->registro.dato!=Dato)
		L=L->sig;
	if(L==NULL)
		printf("\nNo encontrado en la lista");
	return L;
}
void EliminarNodoxDato(tPtr* ini,int Dato){
	tPtr ant,act;
	ant=NULL;
	act=*ini;
	while(act!=NULL && act->registro.dato!=Dato){
		ant=act;
		act=act->sig;
	}
	if(act!=NULL){
		if(ant==NULL)
			*ini=act->sig;
		else
			ant->sig=act->sig;
		act->sig=NULL;
		free(act);
	}
	else
	   printf("\nNo se encontro en la lista\n");
}
void ModificarNodoxDato(tPtr* ini,int Dato){
	tPtr act = *ini;
	while(act!=NULL && act->registro.dato!=Dato)
		act=act->sig;
	if(act!=NULL){
		printf("Modificacion de dato:");
		scanf("%d",&act->registro.dato);
		LimpiaBuffer(getchar());
		printf("Modificacion de otrodato:");
		LeeCad(act->registro.otrodato,Max_Cad);
	}
	else
	   printf("\nNo se encontro en la lista\n");
}
tPtr GenerarNuevaListaxDato(tPtr ini,int Dato){
	tPtr Nuevo,CopiaNodo;
	Nuevo=NULL;
	CopiaNodo=NULL;
	while(ini!=NULL){
		if(ini->registro.dato==Dato){
			CopiaNodo = GeneraCopiaNodo(ini);
			if(CopiaNodo!=NULL)
				CargaxOrden(&Nuevo,CopiaNodo);
		}
		ini=ini->sig;
	}
	return Nuevo;
}
void DepurarListaxDato(tPtr* ini,int Dato){
	tPtr ant,act;
	ant=NULL;
	act=*ini;
	while(act!=NULL){
		if(act->registro.dato==Dato){
			if(ant==NULL){
				*ini=act->sig;
				free(act);
				act=*ini;
			}
			else{
				ant->sig=act->sig;
				free(act);
				act=ant->sig;
			}
		}
		else{
			ant=act;
			act=act->sig;
		}
	}
}
void EliminarRepetidosxDato(tPtr* ini){
	tPtr ant,act,sig;
	ant=NULL;
	act=*ini;
	sig=NULL;
	while(act!=NULL){
		ant=act;
		sig=act->sig;
		while(sig!=NULL){
			if(act->registro.dato==sig->registro.dato){
				ant->sig=sig->sig;
				free(sig);
				sig=ant->sig;
			}
			else{
				ant=sig;
				sig=sig->sig;
			}
		}
		act=act->sig;
	}
}
void MostrarLista(tPtr P){
	while(P!=NULL){
		MostrartReg(P->registro);
		P=P->sig;
	}
}
