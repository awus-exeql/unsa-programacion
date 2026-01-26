#include "registro.h"
tArt GeneratArt(){
	tArt g;
	printf("\nCodigo: ");
	scanf("%d",&g.cod);
	__fpurge(stdin); // Equivalente a fflush
	printf("Nombre: ");
	CargartCadena(g.nomar);
	printf("Proveedor: ");
	CargartCadena(g.nompr);
	printf("Fecha de alta (AAAAMMDD): ");
	scanf("%ld",&g.fecha);
	printf("Cantidad disponible: ");
	scanf("%d",&g.cantd);
	printf("Precio: ");
	scanf("%f",&g.precio);
	__fpurge(stdin);
	return g;
}
void MostrartArt(tArt A){
	printf("\nCodigo: %d",A.cod);
	printf("\nNombre: %s",A.nomar);
	printf("\nProveedor: %s",A.nompr);
	printf("\nFecha de alta: %ld",A.fecha);
	printf("\nCantidad disponible: %d",A.cantd);
	printf("\nPrecio: %f\n",A.precio);
}
int CompxNompr(tArt A1,tArt A2){
	return ComparaCadenas(A1.nompr,A2.nompr);
}
int GetCodigo(tArt A){
	return A.cod;
}
int ComptArtcontCadxNpr(tArt a,tCad c){
	return ComparaCadenas(a.nompr,c);
}
