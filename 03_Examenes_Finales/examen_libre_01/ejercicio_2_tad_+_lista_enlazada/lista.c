#include "lista.h"
void CargarLista(tLis* L){
	int i;
	printf("Cantidad: ");
	scanf("%d",&L->N);
	printf("\n===>     Cargando lista de articulos     <===\n");
	for(i=1;i<=L->N;i++){
		printf("\n===> Articulo N.%d <===\n",i);
		CargaOrdenado(&L->Lista,CrearNodo());
	}
}
void MostrarLista(tLis L){
	MostrartPtr(L.Lista);
}
void EliminarArticuloxCod(tLis* L){
	int cod;
	printf("\nCodigo: ");
	scanf("%d",&cod);
	EliminarNodoxCod(&L->Lista,cod);
}
void ListaxProveedor(tLis ini){
	tCad prv;
	printf("\nProveedor: ");
	CargartCadena(prv);
	printf("\n=======> Articulos que trajo '%s' <=======\n",prv);
	MostrarxProveedor(ini.Lista,prv);
}
