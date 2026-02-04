/*
	Un Observatorio Espacial opera con una lista generada por su telescopio, de cada observacion se 
lleva la siguiente informacion: Codigo, Fecha(aaaammdd), Hora(hhmmss), Coordenada espacial(xxxyyyzzz) 
y Anomalia[1: Colision de cuerpos; 2: Estrella; 3: Meteorito o 4: Energia luminica].
	Se solicita crear un programa convenientemente modularizado que, utilizando Lista Simplemente 
Enlazada, permita cargar la lista de N observaciones, las que se ordenaran por codigo, a medida 
que se ingresan los registros. Posteriormente eliminar los registros cuya fecha coincide con un mes 
y año dado. Por ultimo, mostrar la lista resultante.
*/
#include <stdio_ext.h>
#include <stdlib.h>
typedef struct{
	int cod,anlia;
	long fecha,hora,coords;
}tObs;
typedef struct nodo{
	tObs obs;
	struct nodo* sig;
}tNodo;
typedef tNodo* tPtr;
// PROTOTIPOS DE FUNCIONES
tObs GeneraObs();
void MostrarObs(tObs);
tPtr CrearNodo();
void CargaOrdenada(tPtr*,tPtr);
void EliminarxFecha(tPtr*,long);
void MostrarLista(tPtr);
int main(void){
	tPtr L;
	int N,i;
	long fecha;
	printf("Cantidad de observaciones: ");
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		printf("\nObservacion N.%d\n",i);
		CargaOrdenada(&L,CrearNodo());
	}
	printf("\n=======> Mostrando lista ordenada <=======\n");
	MostrarLista(L);
	printf("\nFecha para eliminar (aaaamm): ");
	scanf("%ld",&fecha);
	EliminarxFecha(&L,fecha);
	printf("\n=======> Mostrando lista <=======\n");
	MostrarLista(L);
	return 0;
}
tObs GeneraObs(){
	tObs g;
	printf("\nCodigo: ");
	scanf("%d",&g.cod);
	printf("Fecha (aaaammdd): ");
	scanf("%ld",&g.fecha);
	printf("Hora (hhmmss): ");
	scanf("%ld",&g.hora);
	printf("Coordenada espacial (xxxyyyzzz): ");
	scanf("%ld",&g.coords);
	printf("Anomalia (1: Colision de cuerpos; 2: Estrella; 3: Meteorito o 4: Energia luminica): ");
	scanf("%d",&g.anlia);
	return g;
}
void MostrarObs(tObs O){
	printf("\nCodigo: %d",O.cod);
	printf("\nFecha: %ld",O.fecha);
	printf("\nHora: %ld",O.hora);
	printf("\nCoordenada espacial: %ld",O.coords);
	printf("\nAnomalia: %d\n",O.anlia);
}
tPtr CrearNodo(){
	tPtr Nuevo = (tPtr)malloc(sizeof(tNodo));
	if(Nuevo!=NULL){
		Nuevo->obs=GeneraObs();
		Nuevo->sig=NULL;
	}
	else
	   printf("\nError!, memoria llena\n");
	return Nuevo;
	
}
void CargaOrdenada(tPtr* ini,tPtr Nuevo){
	tPtr act,ant;
	act=*ini;
	ant=NULL;
	while(act!=NULL && act->obs.cod<Nuevo->obs.cod){
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
void EliminarxFecha(tPtr* ini,long fecha){
	tPtr ant,act;
	ant=NULL;
	act=*ini;
	while(act!=NULL){
		if((act->obs.fecha/100) == fecha){
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
void MostrarLista(tPtr L){
	int i;
	i=0;
	while(L!=NULL){
		i++;
		printf("\nObservacion N.%d\n",i);
		MostrarObs(L->obs);
		L=L->sig;
	}
}
