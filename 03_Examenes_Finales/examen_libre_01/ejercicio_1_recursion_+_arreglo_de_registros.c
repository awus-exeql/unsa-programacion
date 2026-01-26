/*
	Un Sistema Medico tiene una lista con la siguiente informacion: Codigo de atencion, DNI del 
paciente, Obra Social del paciente, Fecha de atencion,Tipo de atencion (Pediatria [P], Familia [F], 
Clinica [C]).
	Se solicita crear un programa convenientemente modularizado que, utilizando arreglo de registros 
y modulos recursivos, permita cargar  la lista de N atenciones y luego ordenarla por codigo, utilizando 
el metodo de QSort. Posteriormente el programa presentara un menu con las siguientes opciones:
	a) Mostrar los datos de las atenciones posteriores a una fecha ingresada.
	b) Informar la cantidad de atenciones realizadas, segun el Tipo de atencion.
	c) Dado un Codigo de atencion, eliminar el registro de la lista.
*/
#include <stdio.h>
#include <string.h>

#define Max_Cad 30
#define Max_List 30

typedef char tCad[Max_Cad];
typedef struct{
	int cod;
	long dni,fechadat;
	tCad os;
	char tipoda;
}tPaciente;
typedef tPaciente tLista[Max_List];
//PROTOTIPOS
void LimpiaBuffer(char);
void LeeCad(tCad,int,int);
tPaciente GentPaciente();
void MostrartPaciente(tPaciente);
void CargarLista(tLista,int);
void MostrarLista(tLista,int);
void QSort(tLista,int,int);
void ListaPostFecha(tLista,int,long);
int ContxtAtencion(tLista,int,char);
void CantxtAtencion(tLista,int);
int PosxCod(tLista,int,int);
void Corrimiento(tLista,int,int);
void EliminarxCod(tLista,int*,int);
int Opciones();
void Menu(tLista,int*);
int main(void){
	int N;
	tLista L;
	printf("Cantidad de consultas: ");
	scanf("%d",&N);
	CargarLista(L,N);
	printf("\n=======> Aplicando ordenamiento QSort a la lista <=======\n");
	QSort(L,1,N);
	MostrarLista(L,N);
	Menu(L,&N);
	return 0;
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
tPaciente GentPaciente(){
	tPaciente g;
	printf("\nCodigo de atencion: ");
	scanf("%d",&g.cod);
	printf("DNI: ");
	scanf("%ld",&g.dni);
	LimpiaBuffer(getchar());
	printf("Obra social: ");
	LeeCad(g.os,0,Max_Cad);
	printf("Fecha de atencion (formato AAAAMMDD): ");
	scanf("%ld",&g.fechadat);
	printf("Tipo de atencion (Pediatria [P], Familia [F], Clinica [C]): ");
	scanf(" %c",&g.tipoda);
	return g;
}
void MostrartPaciente(tPaciente p){
	printf("\nCodigo de atencion: %d",p.cod);
	printf("\nDNI: %ld",p.dni);
	printf("\nObra social: %s",p.os);
	printf("\nFecha de atencion: %ld",p.fechadat);
	switch(p.tipoda){
	case 'P':
		printf("\nTipo de atencion: Pediatria\n");
		break;
	case 'F':
		printf("\nTipo de atencion: Familia\n");
		break;
	case 'C':
		printf("\nTipo de atencion: Clinica\n");
		break;
	default:
		printf("\nDato mal ingresado! Corregir.\n");
	}
}
void CargarLista(tLista L,int n){
	if(n>0){
		CargarLista(L,n-1);
		printf("\n==> Datos paciente [%d] <==\n",n);
		L[n]=GentPaciente();
	}
}
void MostrarLista(tLista L,int n){
	if(n>0){
		MostrarLista(L,n-1);
		printf("\n==> Datos paciente [%d] <==\n",n);
		MostrartPaciente(L[n]);
	}
}
void QSort(tLista V,int ini,int fin){
	int izq,der;
	tPaciente piv;
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
void ListaPostFecha(tLista L,int N,long f){
	if(N>0){
		ListaPostFecha(L,N-1,f);
		if(L[N].fechadat>f){
			printf("\n=> Atencion [%d] <=\n",N);
			MostrartPaciente(L[N]);
		}
	}
}
int ContxtAtencion(tLista L,int N,char tA){
	if(N>0){
		if(L[N].tipoda==tA)
			return 1+ContxtAtencion(L,N-1,tA);
		else
			return ContxtAtencion(L,N-1,tA);
	}
	else
	   return 0;
}
void CantxtAtencion(tLista L,int N){
	printf("\nCantidad de atenciones por Pediatria: %d\n",ContxtAtencion(L,N,'P'));
	printf("\nCantidad de atenciones por Familia: %d\n",ContxtAtencion(L,N,'F'));
	printf("\nCantidad de atenciones por Clinica: %d\n",ContxtAtencion(L,N,'C'));
}
int PosxCod(tLista L,int N,int cod){
	if(N>0){
		if(L[N].cod==cod)
			return N;
		else
			return PosxCod(L,N-1,cod);
	}
	else
	   return 0;
}
void Corrimiento(tLista L,int N,int pos){
	if(pos<N){
		L[pos]=L[pos+1];
		Corrimiento(L,N,pos+1);
	}
}
void EliminarxCod(tLista L,int* N,int cod){
	int pos;
	pos=PosxCod(L,*N,cod);
	Corrimiento(L,*N,pos);
	--*N;
}
int Opciones(){
	int op;
	printf("\nMENU\n");
	printf("\n(1) Mostrar las atenciones posteriores a una fecha");
	printf("\n(2) Cantidad de atenciones realizadas por tipo de atencion");
	printf("\n(3) Eliminar una atencion por codigo");
	printf("\n(0) Salir");
	printf("\nEleccion: ");
	scanf("%d",&op);
	LimpiaBuffer(getchar());
	return op;
}
void Menu(tLista L,int* n){
	int op,cod;
	long f;
	op=Opciones();
	if(op){
		switch(op){
		case 1:
			printf("\nFecha (AAAAMMDD): ");
			scanf("%ld",&f);
			printf("\n=====> Lista de atenciones posteriores a la fecha: %ld <=====\n",f);
			ListaPostFecha(L,*n,f);
			break;
		case 2:
			CantxtAtencion(L,*n);
			break;
		case 3:
			printf("\nCodigo: ");
			scanf("%d",&cod);
			EliminarxCod(L,n,cod);
			break;
		default:
			printf("\nOpcion invalida!\n");
		}
		Menu(L,n);
	}
}
