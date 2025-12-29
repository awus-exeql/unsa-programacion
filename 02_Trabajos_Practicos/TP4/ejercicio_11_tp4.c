/*
	Un Mini Mercado lleva una lista de M productos, de cada producto guarda la siguiente 
informacion: Codigo de producto, Codigo de proveedor, Cantidad del producto y Precio de 
venta del producto. Se solicita ingresar la lista de productos y que la misma se ordene 
a medida que se ingresan los productos por el codigo de producto. Cada 15 dias recibe de 
un proveedor una lista actualizada de N productos con sus nuevos precios de venta, esta 
nueva lista no se encuentra ordenada.
	Se solicita actualizar los precios de la lista de productos del Mini Mercado e informar 
cuantos productos se actualizaron con nuevos precios de ventas. Si un producto de lista de
actualizacion no se encuentra en la lista del Mini Mercado, agregarlo (considerar cantidad 
en cero), informando cuantos productos nuevos se han agregado.
*/
#include <stdio.h>
#define Max_Vec 30
typedef int tVecInt[Max_Vec];
typedef float tVecFloat[Max_Vec];
// PROTOTIPOS
void IngresoUnoOrdenado(tVecInt,tVecInt,tVecInt,tVecFloat,int,int,int,int,float);
void IngresoLista(tVecInt,tVecInt,tVecInt,tVecFloat,int);
void MostrarLista(tVecInt,tVecInt,tVecInt,tVecFloat,int);

int main(void){
	int M;
	tVecInt CdPr,CdPv,CantP;
	tVecFloat Precio;
	printf("Tamaño de lista: ");
	scanf("%d",&M);
	IngresoLista(CdPr,CdPv,CantP,Precio,M);
	printf("\nLISTA INGRESADA\n");
	MostrarLista(CdPr,CdPv,CantP,Precio,M);
	return 0;
}
void IngresoUnoOrdenado(tVecInt CdPr,tVecInt CdPv,tVecInt CantP,tVecFloat Precio,int N,int CdPrN,int CdPvN,int CantPN,float PrecioN){
	int j;
	CdPr[0]=CdPrN;
	j=N-1;
	while(CdPr[0]<CdPr[j]){
		CdPr[j+1]=CdPr[j];
		CdPv[j+1]=CdPv[j];
		CantP[j+1]=CantP[j];
		Precio[j+1]=Precio[j];
		j--;
	}
	CdPr[j+1]=CdPrN;
	CdPv[j+1]=CdPvN;
	CantP[j+1]=CantPN;
	Precio[j+1]=PrecioN;
}
void IngresoLista(tVecInt CdPr,tVecInt CdPv,tVecInt CantP,tVecFloat Precio,int N){
	int i,CdPrN,CdPvN,CantPN;
	float PrecioN;
	for(i=1;i<=N;i++){
		printf("\nProducto [%d]\n",i);
		printf("Codigo de producto: ");
		scanf("%d",&CdPrN);
		printf("Codigo de proveedor: ");
		scanf("%d",&CdPvN);
		printf("Cantidad de producto: ");
		scanf("%d",&CantPN);
		printf("Precio: ");
		scanf("%f",&PrecioN);
		IngresoUnoOrdenado(CdPr,CdPv,CantP,Precio,i,CdPrN,CdPvN,CantPN,PrecioN);
	}
}
void MostrarLista(tVecInt CdPr,tVecInt CdPv,tVecInt CantP,tVecFloat Precio,int N){
	int i;
	for(i=1;i<=N;i++){
		printf("\nProducto [%d]\n",i);
		printf("Codigo de producto: %d",CdPr[i]);
		printf("\nCodigo de proveedor: %d",CdPv[i]);
		printf("\nCantidad de producto: %d",CantP[i]);
		printf("\nPrecio: %f\n",Precio[i]);
	}
}
