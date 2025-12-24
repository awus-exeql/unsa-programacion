/*Ejercicio 10: Una entrenadora de ciclismo lleva una lista con informacion de N entrenamientos
realizados por un ciclista. Para cada entrenamiento se tiene la siguiente informacion: la Velocidad del
ciclista, el Tiempo transcurrido (en segundos), La fecha de realizacion (Dia/Mes/Año), y un Numero de
identificacion para cada sesion. 
Se solicita ingresar la lista de entrenamientos y, dado un valor de velocidad V, 
determinar cuantos entrenamientos presentan un valor mayor al ingresado. Calcular el
promedio de las velocidades de los entrenamientos, Ademas, dado un tiempo T, mostrar las actividades
cuyo tiempo se encuentren en el intervalo [T-30 segundos y T+30 segundos].*/
#include <stdio.h>
#define Max_List 30
typedef int TVec[Max_List];
// PROTOTIPOS
void IngresoLista(TVec,TVec,TVec,TVec,int);
int CantVelMay(TVec,int,int);
int PromVel(TVec,int);

int main(void){
	TVec Velocidad,Tiempo,Fecha,ID;
	int tam,vel,cantvelmay;
	printf("Cantidad de entrenamientos: ");
	scanf("%d",&tam);
	IngresoLista(Velocidad,Tiempo,Fecha,ID,tam);
	printf("\n\nVelocidad: ");
	scanf("%d",&vel);
	cantvelmay=CantVelMay(Velocidad,tam,vel);
	printf("\nCantidad de velodidades mayores a '%d' es: %d\n",vel,cantvelmay);
	
	return 0;
}
void IngresoLista(TVec Velocidad,TVec Tiempo, TVec Fecha,TVec ID,int N){
	int i;
	for(i=1;i<=N;i++){
		printf("\n[%d] Entrenamiento\n",i);
		printf("Velocidad: ");
		scanf("%d",&Velocidad[i]);
		printf("Tiempo: ");
		scanf("%d",&Tiempo[i]);
		printf("Fecha (DDMMAAAA): ");
		scanf("%d",&Fecha[i]);
		printf("Identificacion: ");
		scanf("%d",&ID[i]);
	}
}
int CantVelMay(TVec Velocidad,int N,int V){
	int cont,i;
	cont=0;
	for(i=1;i<=N;i++){
		if(Velocidad[i]>V)
			cont++;
	}
	return cont;
}
int PromVel(TVec Velocidad,int N){
	int i,acu;
	acu=0;
	for(i=1;i<=N;i++)
		acu+=Velocidad[i];
	return acu/N;
}
