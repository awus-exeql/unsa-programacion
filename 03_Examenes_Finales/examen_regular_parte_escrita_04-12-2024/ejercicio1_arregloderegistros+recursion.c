/*
	Un Centro de mediacion lleva una lista de N Mediaciones. De cada Mediacion lleva la siguiente 
informacion: Codigo de mediacion, Demandante, Demandado, Mediador, Objeto de la mediacion, Fecha 
de inicio, Fecha de finalizacion.
	Realizar un programa modular recursivo que, utilizando Arreglo de registros permita ingresar 
la lista de N mediaciones, atendiendo que no se permiten registros repetidos y que la Fecha de 
finalizacion se inicializa en vacio. A continuacion, utilizando el metodo de QSort ordene la lista 
por el campo Codigo de la mediacion y luego realizar las siguientes operaciones mediante un menu:
	(a) Mostrar la lista de mediacion.
	(b) Dado el Codigo de mediacion, modificar la Fecha de finalizacion del registro, ingresando
	la misma.
	(c) Dada una Fecha de finalizacion, eliminar los registros con dicha fecha de finalizacion.

*/
#include <stdio_ext.h>
#define Max_Cad 30
#define Max_List 20
typedef char tCad[Max_Cad];
typedef struct{
	int cod;
	tCad Dte,Ddo,Mdor,ObMn;
	long fIni,fFin;
}tMed;
typedef tMed tList[Max_List];
// PROTOTIPOS DE FUNCIONES
void LimpiaBuffer(char);
void LeeCad(tCad,int,int);
tMed GeneraMed();
int BusqSec(tList,int,int);
tMed GeneraMedSinRepetir(tList,int);
void MostrarMed(tMed);
void CargarLista(tList,int);
void MostrarLista(tList,int);
void QSort(tList,int,int);
int BusqBin(tList,int,int,int);
void ModificarFechaFinal(tList,int,int);
void Corrimiento(tList,int,int);
void EliminarxFechaFinal(tList,int*,int,long);
int Opciones();
void Menu(tList,int*);
int main(void){
	tList L;
	int n;
	printf("Cantidad de mediaciones: ");
	scanf("%d",&n);
	CargarLista(L,n);
	QSort(L,1,n);
	Menu(L,&n);
	return 0;
}
void LimpiaBuffer(char c){
	if(c!='\n' && c!=EOF){
		c=getchar();
		LimpiaBuffer(c);
	}
}
void LeeCad(tCad C,int i,int N){
	char c;
	c=getchar();
	if(c!='\n' && c!=EOF && i<N-1){
		C[i]=c;
		LeeCad(C,i+1,N);
	}
	else{
		C[i]='\0';
		LimpiaBuffer(c);
	}
}
tMed GeneraMed(){
	tMed G;
	printf("\nCodigo: ");
	scanf("%d",&G.cod);
	__fpurge(stdin); // equivalente a fflush
	printf("Demandante: ");
	LeeCad(G.Dte,0,Max_Cad);
	printf("Demandado: ");
	LeeCad(G.Ddo,0,Max_Cad);
	printf("Mediador: ");
	LeeCad(G.Mdor,0,Max_Cad);
	printf("Objeto: ");
	LeeCad(G.ObMn,0,Max_Cad);
	printf("Fecha de inicio: ");
	scanf("%ld",&G.fIni);
	G.fFin=0;
	return G;
}
int BusqSec(tList L,int N,int bus){
	if(N>0){
		if(L[N].cod==bus)
			return N;
		else
			return BusqSec(L,N-1,bus);
	}
	else
	   return 0;
}
tMed GeneraMedSinRepetir(tList L,int N){
	tMed M;
	M=GeneraMed();
	if(BusqSec(L,N-1,M.cod)) // (N-1) Porque empezamos a buscar una posicion atras.
		// En (N) no tenemos nada asignado aun.
		return GeneraMedSinRepetir(L,N);
	else
		return M;
}
void MostrarMed(tMed M){
	printf("\nCodigo: %d",M.cod);
	printf("\nDemandante: %s",M.Dte);
	printf("\nDemandado: %s",M.Ddo);
	printf("\nMediador: %s",M.Mdor);
	printf("\nObjeto: %s",M.ObMn);
	printf("\nFecha de inicio: %ld",M.fIni);
	printf("\nFecha de finalizacion: %ld\n",M.fFin);
}
void CargarLista(tList L,int N){
	if(N>0){
		CargarLista(L,N-1);
		printf("\nMediacion N.%d\n",N);
		L[N]=GeneraMedSinRepetir(L,N);
	}
}
void MostrarLista(tList L,int N){
	if(N>0){
		MostrarLista(L,N-1);
		printf("\nMediacion N.%d\n",N);
		MostrarMed(L[N]);
	}
}
void QSort(tList V,int ini,int fin){
	int izq,der;
	tMed piv;
	if(ini<fin){
		piv=V[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der && V[der].cod>piv.cod)
				der--;
			if(izq<der){
				V[izq]=V[der];
				izq++;
			}
			while(izq<der && V[izq].cod<piv.cod)
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
int BusqBin(tList L,int ini,int fin,int bus){
	int med;
	if(ini<=fin){
		med=(ini+fin)/2;
		if(L[med].cod==bus)
			return med;
		else{
			if(L[med].cod<bus)
				return BusqBin(L,med+1,fin,bus);
			else
				return BusqBin(L,ini,med-1,bus);
		}
	}
	else
	   return 0;
}
void ModificarFechaFinal(tList L,int N,int cod){
	int p;
	p=BusqBin(L,1,N,cod);
	if(p){
		printf("\nModificando fecha de finalizacion\n");
		printf("\nMediacion N.%d",p);
		printf("\nFecha de finalizacion: ");
		scanf("%ld",&L[p].fFin);
	}
	else
	   printf("\nCodigo invalido!\n");
}
void Corrimiento(tList L,int N,int p){
	if(p<N){
		L[p]=L[p+1];
		Corrimiento(L,N,p+1);
	}
}
void EliminarxFechaFinal(tList L,int* N,int i,long bus){
	if(*N>0 && i<=*N){
		if(L[i].fFin==bus){
			Corrimiento(L,*N,i);
			(*N)--;
			EliminarxFechaFinal(L,N,i,bus);
		}
		else
		   EliminarxFechaFinal(L,N,i+1,bus);
	}
}
int Opciones(){
	int op;
	printf("\nMENU\n");
	printf("\n(1) Mostrar la lista");
	printf("\n(2) Modificar fecha final por Codigo de mediacion");
	printf("\n(3) Eliminar mediaciones por fecha final");
	printf("\n(0) Salir");
	printf("\nEleccion: ");
	scanf("%d",&op);
	__fpurge(stdin);
	return op;
}
void Menu(tList L,int* n){
	int op,cod;
	long fech;
	op=Opciones();
	if(op){
		switch(op){
		case 1:
			printf("\nMostrando lista\n");
			MostrarLista(L,*n);
			break;
		case 2:
			printf("\nCodigo: ");
			scanf("%d",&cod);
			ModificarFechaFinal(L,*n,cod);
			break;
		case 3:
			printf("\nFecha: ");
			scanf("%ld",&fech);
			EliminarxFechaFinal(L,n,1,fech);
			break;
		default:
			printf("\nOpcion invalida!\n");
		}
		Menu(L,n);
	}
}
