/*
	Un Sistema Medico tiene una lista con la siguiente informacion: Codigo de atencion, DNI del 
paciente, Obra Social del paciente, Fecha de atencion, Tipo de atencion (Pediatria[P], Familia[F], 
Clinica[C]).
	Se solicita crear un programa convenientemente modularizado que, utilizando arreglo de registros 
y modulos recursivos, permita cargar la lista de N atenciones y luego ordenarla por codigo, utilizando 
el metodo de QSort. Posteriormente, dado un Codigo de atencion eliminar el registro de la lista.
	Mostrar la lista modificada.
*/
#include <stdio_ext.h>
#define Max_Cad 30
#define Max_List 20
typedef char tCad[Max_Cad];
typedef struct{
	int cod;
	long dni,fecha;
	tCad os;
	char tpa;
}tAtn;
typedef tAtn tLis[Max_List];
// PROTOTIPOS
void LimpiaBuffer(char);
void LeeCad(tCad,int,int);
tAtn GeneratAtn();
void MostrartAtn(tAtn);
void CargarLista(tLis,int);
void MostrarLista(tLis,int);
void QSort(tLis,int,int);
int BusqBin(tLis,int,int,int);
void Corrimiento(tLis,int,int);
void EliminarxCod(tLis,int*,int);
int main(void){
	tLis l;
	int N,cod;
	printf("Cantidad de atenciones: ");
	scanf("%d",&N);
	CargarLista(l,N);
	QSort(l,1,N);
	printf("\nCodigo de atencion a eliminar: ");
	scanf("%d",&cod);
	EliminarxCod(l,&N,cod);
	MostrarLista(l,N);
}
void LimpiaBuffer(char c){
	if(c!='\n' && c!=EOF){
		c=getchar();
		LimpiaBuffer(c);
	}
}
void LeeCad(tCad C,int i,int tam){
	char c;
	c=getchar();
	if(c!='\n' && c!=EOF && i<tam-1){
		C[i]=c;
		LeeCad(C,i+1,tam);
	}
	else{
		C[i]='\0';
		LimpiaBuffer(c);
	}
}
tAtn GeneratAtn(){
	tAtn g;
	printf("\nCodigo: ");
	scanf("%d",&g.cod);
	printf("DNI del paciente: ");
	scanf("%ld",&g.dni);
	__fpurge(stdin); // equivalente a fflush en gnulinux
	printf("Obra social: ");
	LeeCad(g.os,0,Max_Cad);
	printf("Fecha de atencion (AAAAMMDD): ");
	scanf("%ld",&g.fecha);
	printf("Tipo de atencion (Pediatria[P], Familia[F], Clinica[C]): ");
	scanf(" %c",&g.tpa);
	return g;
}
void MostrartAtn(tAtn a){
	printf("\nCodigo: %d",a.cod);
	printf("\nDNI del paciente: %ld",a.dni);
	printf("\nObra social: %s",a.os);
	printf("\nFecha de atencion: %ld",a.fecha);
	printf("\nTipo de atencion: %c",a.tpa);
}
void CargarLista(tLis L,int N){
	if(N>0){
		CargarLista(L,N-1);
		printf("\nAtencion N.%d\n",N);
		L[N]=GeneratAtn();
	}
}
void MostrarLista(tLis L,int N){
	if(N>0){
		MostrarLista(L,N-1);
		printf("\nAtencion N.%d\n",N);
		MostrartAtn(L[N]);
	}
}
void QSort(tLis V,int ini,int fin){
	int izq,der;
	tAtn piv;
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
int BusqBin(tLis L,int ini,int fin,int cod){
	int med;
	if(ini<=fin){
		med=(ini+fin)/2;
		if(L[med].cod==cod){
			return med;
		}
		else{
			if(L[med].cod<cod){
				return BusqBin(L,med+1,fin,cod);
			}
			else{
				return BusqBin(L,ini,med-1,cod);
			}
		}
	}
	else{
		return 0;
	}
}
void Corrimiento(tLis L,int N,int p){
	if(p<N){
		L[p]=L[p+1];
		Corrimiento(L,N,p+1);
	}
}
void EliminarxCod(tLis L,int* N,int cod){
	int p;
	p=BusqBin(L,1,*N,cod);
	Corrimiento(L,*N,p);
	(*N)--;
}
