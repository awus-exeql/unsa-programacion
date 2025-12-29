#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	tReg dato;
	struct nodo *sig;
}tNodo;

typedef tNodo *tPtr;
}
int main(int argc, char *argv[]) {
	
	return 0;
}
void ingresoIncondicionado(tVec a,int n){ //con registros. En un modulo ingreso se pide el N y se llama a este mod
	if(n>0){
		ingresoIncondicionado(a,n-1);
		a[n]=cargaReg();
	}
}
tReg cargaSinRepetir(tVec a,int n){
	tReg aux=cargaUno();
	if(busqSecR(a,n,aux.cod)!=-1){ //busca el elemento cargado en el vector
		printf("\nCodigo invalido, coincide con uno ya cargado previamente ");
		return cargaSinRepetir(a,n);//se carga otro codigo
	}
	else 
	   return aux;
}
void cargaVec(tVec a,int n){
	if(n>0){ //en otro modulo cargaLista se pediria el n y se llamaria a este mod
		cargaVec(a,n-1);
		a[n]=cargaSinRepetir(a,n-1);
	}
}
void ingresoCond(tVec a,int* n){
	fflush(stdin);
	int rta;
	printf("\nIngrese 1 para nuevo elemento,0 para terminar ingreso");
	scanf("%d",&rta);
	if(rta!=0){
		(*n)++;
		a[n]=cargaReg();
		ingresoCond(a,n);
	}
}
int busqSecR(tVec a,int n,int bus){
	if(n>0){
		if(a[n].cod==bus)
			return n;
		else
			return busqSecR(a,n-1,bus);
	}
	else
	   return -1;
}
int busqBin(tVec a,int ini,int fin, int bus){
	int mid;
	if(ini<=fin){
		mid=(ini+fin)/2;
		if(a[mid]==bus)
			return mid;
		else{
			if(bus<a[mid])
				return busqBin(a,ini,mid-1,bus);
			else
				return busqBin(a,mid+1,fin,bus);
		}
	}
	else
	   return -1;
} 
void limpiaBuffer(char c){
	if(c!=EOF&&c!='\n'){
		c=getchar();
		limpiaBuffer(c);
	}
}
void leeCadR(tCad a,int j,int tam){
	fflush(stdin);
	char c;
	c=getchar();
	if(c!='\n'&&c!=EOF&&j<tam-1){
		a[j]=c;
		leeCadR(a,j+1,tam);
	}
	else{
		a[j]='\0';
		limpiaBuffer(c);
	}
}
void qSort(tVec a,int ini,int fin){
	int izq,der;
	tReg piv;
	if(ini<fin){
		piv=a[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der&&a[der].cod>piv.cod)
				der--;
			if(izq<der){
				a[izq]=a[der];
				izq++;
			}
			while(izq<der&&a[izq].cod<piv.cod)
			   izq++;
			if(izq<der){
				a[der]=a[izq];
				der--;
			}
		}
		a[der]=piv;
		qSort(a,ini,der-1);
		qSort(a,der+1,fin);
	}
}
void merge(tVec a,int ini,int mid,int fin){
	tVec aux;
	int izq,der,ia,k;
	ia=0;
	izq=ini;
	der=mid+1;
	while(izq<=mid&&der<=fin){
		ia++;
		if(a[izq]<a[der]){
			aux[ia]=a[izq];
			izq++;
		}
		else{
			aux[ia]=a[der];
			der++;
		}
	}
	for(k=izq;k<=mid;k++){
		ia++;
		aux[ia]=a[k];
	}
	for(k=der; k<=fin; k++){ 
		ia++; 
		aux[ia]=a[k]; 
	} 
	for(k=1;k<=ia;k++)/*transfiere el vector mezclado al parámetro de salida*/
		a[ini+k-1]=aux[k];
} 
void mSort(tVec a,int ini, int fin){
	int mid;
	if(ini<fin){
		mid=(ini+fin)/2;
		mSort(a,ini,mid);
		mSort(a,mid+1,fin);
		merge(a,ini,mid,fin);
	}  
}
void menuRec(tVec a,int* n){
	int opc;
	opc=muestraMenu();
	if(opc!=0){
		switch(opc){
		case 1: 
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		}
		menuRec(a,n);
	}
}
int muestraMenu(void){
	int opc;
	fflush(stdin);
	printf("\n---MENU DE OPCIONES---");
	printf("\n(1) ");
	printf("\n(2) ");
	printf("\n(3) ");
	printf("\n(0) ");
	printf("\n\nOpcion elegida: ");
	scanf("%d",&opc);
	return opc;
}
	
tPtr creaNodo(void){
	tPtr aux=NULL;
	aux=(tPtr)malloc(sizeof(tNodo));
	aux->dato=CargaReg();
	aux->sig=NULL;
	return aux;
}	
tPtr creaNodoPorCond(tReg aux){
	tPtr nuevo;
	nuevo=(tPtr)malloc(sizeof(tNodo));
	if(nuevo!=NULL){
		nuevo->dato=aux;
		nuevo->sig=NULL;
	}
	else
	   printf("\nError, memoria llena ");
	return aux;
}
tPtr cargaLis(void){
	int i,n;
	tPtr lisAux,nuevo;
	printf("\nIngrese n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		nuevo=creaNodo();
		if(nuevo!=NULL){
			cargaX---(&lisAux,nuevo);
		}
		else
		   printf("\nError, memoria llena");
	}
	return lisAux;
}
void cargaCabeza(tPtr *ini,tPtr nuevo){
	if(*ini==NULL)
		*ini=nuevo;
	else{
		nuevo->sig=*ini;
		*ini=nuevo;
	}
}
void cargaCola(tPtr *ini,tPtr nuevo){
	tPtr ult;
	ult=NULL;
	if(*ini==NULL)
		*ini=nuevo;
	else{
		ult=*ini;
		while(ult->sig!=NULL)
			ult=ult->sig;
		ult->sig=nuevo;
	}
}
void agregaOrdenado(tPtr *ini,tPtr nuevo){
	tPtr ant,act;
	ant=NULL,act=*ini;
	while(act!=NULL&&act->dato.cod<nuevo->dato.cod){
		ant=act;
		act=act->sig;
	}
	if(ant==NULL){
		nuevo->sig=*ini;
		*ini=nuevo;
	}
	else{
		ant->sig=nuevo;
		nuevo->sig=act;
	}
}
void eliminaNodo(tPtr *ini){
	int bus;
	tPtr ant,act;
	ant=NULL,act=*ini;
	printf("\nIngrese ____ a eliminar");
	scanf("%d",&bus);
	while(act!=NULL&&act->dato.cod!=bus){
		ant=act;
		act=act->sig;
	}
	if(act!=NULL){
		if(ant==NULL)
			*ini=act->sig;
		else{
			ant->sig=act->sig;
			
		}
		act->sig=NULL;
		free(act);
	}
	else
	   printf("\nError, no se encontro el elemento");
}
void depuraLista(tPtr *ini){
	tPtr ant,act;
	ant=NULL,act=*ini;
	while(act!=NULL){
		if(tieneqEliminarse(act)){
			if(ant==NULL){
				*ini=act->sig;
				act->sig=NULL;
				free(act);
				act=*ini;
			}
			else{
				ant->sig=act->sig;
				act->sig=NULL;
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
void eliminaRepetidos(tPtr ini) {
	tPtr act,sig,ant;
	act=ini;
	while(act!=NULL){
		ant=act;
		sig=act->sig;
		while (sig!=NULL) {
			if (son iguales(act->dato,sig->dato) {
				ant->sig =sig->sig;
				free(sig);
				sig=ant->sig;
			} else {
				ant=sig;
				sig=sig->sig;
			}
		}
		act=act->sig;
	}
}
	
void genereaNuevaLista(tPtr ini,tPtr *nuevaLista,int cod){/*la lista se genera 
	con los nodos q tengan igual codigo q el cod pasado por parametro*/
	tReg aux;
	tPtr nuevo;
	while(ini!=NULL){
		if(cumpleCondicion(ini->dato){
			aux=ini->dato;
			nuevo=creaNodoPorCond(aux);
			cargaPor___(nuevaLista,nuevo);
		}
			ini=ini->sig;
	}
}
void mostrarLista(tPtr ini){
	if(ini!=NULL){
		while(ini!=NULL){
			muestraReg(ini->dato);
			ini=ini->sig;
		}
	}
	else{
		printf("\nError,no existe lista");
	}
}
