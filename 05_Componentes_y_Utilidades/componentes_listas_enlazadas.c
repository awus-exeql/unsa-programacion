#include <stdio.h>
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
tPtr CargaListaIncondicional();
tPtr CargaListaCondicional();
tPtr BusquedaxDato(tPtr,int);
void EliminarNodoxDato(tPtr*,int);
void ModificarNodoxDato(tPtr*,int);
tPtr GenerarNuevaListaxDato(tPtr,int);
void DepurarListaxDato(tPtr*,int);
void EliminarRepetidosxDato(tPtr*);
void MostrarLista(tPtr);

int main(void) {
	tPtr L;
	L=CargaListaCondicional();
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
	tPtr Copia;
	Copia=NULL;
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
tPtr CargaListaIncondicional(){
	int i,n;
	tPtr Nuevo,Aux;
	Nuevo=NULL;
	Aux=NULL;
	printf("\nCantidad: ");
	scanf("%d",&n);
	LimpiaBuffer(getchar());
	for(i=1;i<=n;i++){
		Aux=CrearNodo();
		if(Aux!=NULL){
			// Acá se implementa cualquier carga de lista que hicimos anteriormente.
			// Por ejemplo, el CargaxOrden.
			CargaxOrden(&Nuevo,Aux);
		}
		else
			printf("\nError, memoria llena");
	}
	return Nuevo;
}
tPtr CargaListaCondicional(){
	int seguir;
	tPtr Nuevo,Aux;
	seguir=1;
	Nuevo=NULL;
	Aux=NULL;
	do{
		if(seguir==1){
			Aux=CrearNodoxCond();
			// La idea de carga es la misma que la Incondicional.
			if(Aux!=NULL)
				CargaxOrden(&Nuevo,Aux);
		}
		else
		   if(seguir!=0)
				printf("\nOpcion invalida\n");
		printf("(1) Cargar,(0) Finalizar:");
		scanf("%d",&seguir);
		LimpiaBuffer(getchar());
	}while(seguir);
	return Nuevo;
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
	tPtr act;
	act=*ini;
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
		if(ini->registro.dato==Dato)
			CopiaNodo = GeneraCopiaNodo(ini);
			if(CopiaNodo!=NULL)
				CargaxOrden(&Nuevo,CopiaNodo);
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
	tPtr ant=NULL;
	tPtr act=*ini;
	tPtr sig=NULL;
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
