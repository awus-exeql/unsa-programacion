/*Ejercicio 4: Se tiene una lista de las edades de N alumnos de una escuela,
se solicita ingresar la lista y a continuacion, mediante un menu:
a) Determinar la edad con mayor cantidad de repeticiones, sabiendo que existe y es unica.
b) Mostrar la primera sublista creciente, de al menos dos numeros, conformada solo por 
elementos pares.*/
#include <stdio.h>
#define Max_List 30
typedef int TVec[Max_List];
//PROTOTIPOS
void CargarVector(TVec,int);
int EdadMasRepetido(TVec,int);
void Sublista(TVec,int);

int main(void) {
	TVec V;
	int n,E;
	printf("Cantidad edades:");
	scanf("%d",&n);
	CargarVector(V,n);
	E=EdadMasRepetido(V,n);
	printf("\nEdad con mas repeticiones:%d\n",E);
	printf("\nBuscando sublista...\n");
	Sublista(V,n);
	return 0;
}
void CargarVector(TVec V,int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Edad en posicion %d:",i);
		scanf("%d",&V[i]);
	}
}
int EdadMasRepetido(TVec V,int n){
	int i,j,f,may,p;
	may=0;
	for(i=1;i<=n;i++){
		V[0]=V[i];
		j=i-1;
		while(V[0]!=V[j])
			j--;
		if(j==0){
			f=1;
			for(j=i+1;j<=n;j++){
				if(V[j]==V[i])
					f++;
			}
			if(may>0){
				if(f>may){
					may=f;
					p=i;
				}
			}
			else{
				may=f;
				p=i;
			}
		}
	}
	return V[p];
}
// VERSION DUDOSA
// Encuentra sublistas pero solo va a mostrar los 2 primeros elementos, si tuviera mas.
/*void Sublista(TVec V,int n){
	int i,cont,k,ini,fin;
	i=k=1;
	cont=0;
	while(i<=n && k!=0){
		if(V[i]%2==0){
			cont++;
			if(ini==0)
				ini=i;
			if(ini!=0)
				fin=i;
		}
		else{
			cont=0;
			ini=0;
			fin=0;
		}
		if(cont>=2)
		   k=0;
		i++;
	}
	if(k==0){
		printf("\nSublista encontrada entre posiciones %d-%d",ini,fin);
		for(i=ini;i<=fin;i++)
			printf("\nEdad en posicion %d = %d",i,V[i]);
	}
	else
	   printf("\nSublista no encontrada\n");
}*/
// Esta cumple las condiciones
/*void Sublista(TVec V,int n){
	int ini,fin,i,b;
	b=1;
	i=1;
	ini=0;
	fin=0;
	while(i<=n && b){
		if(V[i]%2==0){
			if(ini==0 && fin ==0)
				ini=i;
		}
		else{
			fin=i-1;
			if(fin-ini+1>=2)
				b=0;
			else{
				ini=0;
				fin=0;
			}
		}
		if(i==n && V[i]%2==0 && ini>0 && b){
		   fin=i;
		   b=0;
		}
		i++;
	}
	if(b==0){
		printf("\nSublista encontrada entre posiciones %d-%d",ini,fin);
		for(i=ini;i<=fin;i++)
			printf("\nEdad en posicion %d = %d",i,V[i]);
	}
	else
	   printf("\nSublista no encontrada\n");
}*/
// Version mas corta
void Sublista(TVec V, int n) {
	int ini,fin,cont,found,i;
	ini=0; // Indicadores de inicio y fin
	fin=0; // de la sublista, si existe.
	cont=0; // Contador para identificar el caso en el que se cumple la cond de sublista
	found=0; // Bandera que indica si encontramos la sublista
	i=1;
	while(i<=n && !found){
		if(V[i]%2==0){ // Es par?
			cont++; // Contamos cant de pares consecutivos
			if(cont==1)
				ini=i; // Marcamos el inicio del intervalo en la pos del primer par
			if(cont>=2){ // Si hay un segundo par consecutivo
				found=1; // Avisamos que se encontro con la bandera
				fin=i; // Guardamos esta pos en fin
				while(fin<n && V[fin+1]%2==0) // Revisamos si hay mas consecutivos
					fin++;
			}
		}
		else
			cont=0; // Reiniciamos contador
		i++;
	}
	if(found){
		printf("\nSublista encontrada entre posiciones %d-%d",ini,fin);
		for(i=ini;i<=fin;i++)
			printf("\nEdad en posicion %d = %d",i,V[i]);
	}else
		printf("\nSublista no encontrada\n");
}
