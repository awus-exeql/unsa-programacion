#include <stdio.h>
#define Max_Cad 30
#define Max_List 30

typedef char TCad[Max_Cad];

typedef struct{
	int datos;
	TCad masdatos;
}TReg;

typedef TReg TVec[Max_List];

// DECLARACION DE PROTOTIPOS
void LimpiaBuffer(char); //Modificado
void LeeCad(TCad,int,int);
TReg GeneraTReg();
TReg GeneraTRegSinRepetir(TVec,int);
void MostrarTReg(TReg);
void CargarUno(TVec,int*);
void CargarListaIncondicional(TVec,int);
void CargarListaCondicional(TVec,int*);
void MostrarLista(TVec,int);
int BusqBinaria(TVec,int,int,int);
int BusqSecuencial(TVec,int,int);
void EliminarxPosicion(TVec,int*,int);
void AgregarxPosicion(TVec,int*,int,int);
void GenerarNuevaLista(TVec,int,TVec,int*,int criterio);
void QSort(TVec,int,int);
void Merge(TVec,int,int,int);
void MSort(TVec,int,int);
int Opciones();
void Menu(TVec,int*);

int main(void) {
	
	return 0;
}
void LimpiaBuffer(char c){
	if(c!='\n' && c!=EOF){
		c=getchar();
		LimpiaBuffer(c);
	}
}
void LeeCad(TCad C,int i,int tam){
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
TReg GeneraTReg(){
	TReg G;
	printf("\nIngresar datos: ");
	scanf("%d",&G.datos);
	
	LimpiaBuffer(getchar());
	
	printf("Ingresar mas datos: ");
	LeeCad(G.masdatos,0,Max_Cad);
	return G;
}
TReg GeneraTRegSinRepetir(TVec V,int n){
	TReg G;
	G=GeneraTReg();
	if(BusqSecuencial(V,n-1,G.datos) > 0) // (n-1) Porque empezamos a buscar una posicion atras.
		// Ya que en (n) no tenemos nada asignado aun.
		return GeneraTRegSinRepetir(V,n);
	else
		return G;
}
void MostrarTReg(TReg R){
	printf("Datos: %d",R.datos);
	printf("\nMas datos: %s",R.masdatos);
}
void CargarUno(TVec V,int* n){
	++*n;
	V[*n]=GeneraTReg();
}
void CargarListaIncondicional(TVec V,int n){
	if(n > 0){
		CargarListaIncondicional(V,n-1);
		printf("=== Registro[%d] ===",n);
		V[n]=GeneraTReg();
	}
}
void CargarListaCondicional(TVec V,int* n){
	int seguir;
	printf("(1) cargar,(0) finalizar:");
	scanf("%d",&seguir);
	if(seguir){
		++*n;
		printf("=== Registro[%d] ===",*n);
		V[*n]=GeneraTReg();
		CargarListaCondicional(V,n);
	}
}
void MostrarLista(TVec V,int n){
	if(n>0){
		MostrarLista(V,n-1);
		printf("\n=== Registro[%d] ===\n",n);
		MostrarTReg(V[n]);
	}
}
int BusqBinaria(TVec V,int ini,int fin,int DatoBusq){
	int med;
	if(ini <= fin){
		med=(ini+fin)/2;
		if(V[med].datos == DatoBusq)
			return med;
		else{
			if(V[med].datos < DatoBusq)
				return BusqBinaria(V,med+1,fin,DatoBusq);
			else
				return BusqBinaria(V,ini,med-1,DatoBusq);
		}
	}
	else
	   return -1;
}
int BusqSecuencial(TVec V,int n,int DatoBusq){
	if(n > 0){
		if(V[n].datos == DatoBusq)
			return n;
		else
			return BusqSecuencial(V,n-1,DatoBusq);
	}
	else
	   return -1;
}
void EliminarxPosicion(TVec V,int* n,int p){
	if(p < *n){
		V[p]=V[p+1];
		EliminarxPosicion(V,n,p+1);
	}
	else
		--*n;
}
void AgregarxPosicion(TVec V,int* n,int p,int M){
	if(M >= p){
		V[M+1] = V[M];
		AgregarxPosicion(V,n,p,M-1);
	}
	else{
		V[p] = GeneraTReg();
		++*n;
	}
}
void GenerarNuevaLista(TVec V,int n,TVec G,int* m,int criterio){
	if(n > 0){
		if(V[n].datos < criterio){
			++*m;
			G[*m]=V[n];
		}
		GenerarNuevaLista(V,n-1,G,m,criterio);
	}
}
void QSort(TVec V,int ini,int fin){
	int izq,der;
	TReg piv;
	if(ini<fin){
		piv=V[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der && V[der].datos>piv.datos)
				der--;
			if(izq<der){
				V[izq]=V[der];
				izq++;
			}
			while(izq<der && V[izq].datos<piv.datos)
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
void Merge(TVec V,int ini,int med,int fin){
	int izq,der,ia,k;
	TVec aux;
	ia=0;
	izq=ini;
	der=med+1;
	while(izq<=med && der<=fin){
		ia++;
		if(V[izq].datos<V[der].datos){
			aux[ia]=V[izq];
			izq++;
		}
		else{
			aux[ia]=V[der];
			der++;
		}
	}
	for(k=izq;k<=med;k++){
		ia++;
		aux[ia]=V[k];
	}
	for(k=der;k<=fin;k++){
		ia++;
		aux[ia]=V[k];
	}
	for(k=1;k<=ia;k++){
		V[ini+k-1]=aux[k];
	}
}
void MSort(TVec V,int ini,int fin){
	int med;
	if(ini<fin){
		med=(ini+fin)/2;
		MSort(V,ini,med);
		MSort(V,med+1,fin);
		Merge(V,ini,med,fin);
	}
}
int Opciones(){
	int opc;
	printf("(1) Acciones");
	printf("(2) a");
	printf("(3) Implentar");
	printf("(0) Salir");
	scanf("%d",&opc);
	return opc;
}
void Menu(TVec V,int* n){
	int op;
	op=Opciones();
	if(op){
		switch(op){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			printf("Opcion Invalida");
			break;
		}
		Menu(V,n);
	}
}
