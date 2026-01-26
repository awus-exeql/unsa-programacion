#include "puntero.h"
tPtr CrearNodo(){
	tPtr Nuevo = (tPtr)malloc(sizeof(tNodo));
	Nuevo->reg=GeneratArt();
	Nuevo->sig=NULL;
	return Nuevo;
}
void CargaOrdenado(tPtr* ini,tPtr Nuevo){
	tPtr act,ant;
	act=*ini;
	ant=NULL;
	while(act!=NULL && CompxNompr(act->reg,Nuevo->reg)==-1){
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
void MostrartPtr(tPtr L){
	int i;
	i=0;
	while(L!=NULL){
		i++;
		printf("\nArticulo N.%d\n",i);
		MostrartArt(L->reg);
		L=L->sig;
	}
}
int GetCodigoxtPtr(tPtr P){
	return GetCodigo(P->reg);
}
void EliminarNodoxCod(tPtr* ini,int cod){
	tPtr ant=NULL;
	tPtr act=*ini;
	while(act!=NULL && GetCodigoxtPtr(act)!=cod){
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
void MostrarxProveedor(tPtr ini,tCad Prv){
	int i,b;
	i=1;
	b=1;
	while(ini!=NULL){
		if(ComptArtcontCadxNpr(ini->reg,Prv)==0){
			b=0;
			printf("\nArticulo N.%d\n",i);
			MostrartArt(ini->reg);
		}
		i++;
		ini=ini->sig;
	}
	if(b)
		printf("\nNo se encontraron articulos del proveedor\n");
}
