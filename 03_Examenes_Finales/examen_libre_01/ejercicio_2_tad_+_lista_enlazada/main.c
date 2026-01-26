/*
	Una tienda de mascotas lleva una lista de articulos que comercializa en su tienda central y 
sucursales. De cada articulo registra la siguiente informacion: Codigo de articulo, Nombre de 
articulo, Nombre del proveedor, Fecha de alta, Cantidad disponible y Precio.
	Se pide crear un programa que ingrese una lista de N articulos ordenandolos a medida que se 
ingresan segun el nombre del proveedor y luego presente un menu con las siguientes opciones: 
	(a) Mostrar la lista de articulos.
	(b) Dado un Codigo de articulo,eliminarlo de la lista.
	(c) Dado un Proveedor, mostrar los articulos que se comercializan en las tiendas.
*/
#include "lista.h"
int opciones();
void menu(tLis*);
int main(void){
	tLis L;
	CargarLista(&L);
	printf("\n=======> Lista cargada y ordenada <=======\n");
	MostrarLista(L);
	menu(&L);
	return 0;
}
int opciones(){
	int op;
	printf("\nMENU\n");
	printf("\n(1) Mostrar lista de articulos");
	printf("\n(2) Eliminar un articulo de la lista por su codigo");
	printf("\n(3) Mostrar articulos de la lista de un proveedor");
	printf("\n(0) Salir");
	printf("\nEleccion: ");
	scanf("%d",&op);
	__fpurge(stdin);
	return op;
}
void menu(tLis* l){
	int op;
	op=opciones();
	if(op){
		switch(op){
		case 1:
			MostrarLista(*l);
			break;
		case 2:
			EliminarArticuloxCod(l);
			break;
		case 3:
			ListaxProveedor(*l);
			break;
		default:
			printf("\nOpcion invalida\n");
		}
		menu(l);
	}
}
