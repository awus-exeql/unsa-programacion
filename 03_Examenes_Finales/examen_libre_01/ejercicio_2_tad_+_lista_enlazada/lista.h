#ifndef LISTA_H
#define LISTA_H

#include "puntero.h"

typedef struct{
	tPtr Lista;
	int N;
}tLis;

void CargarLista(tLis*);
void MostrarLista(tLis);
void EliminarArticuloxCod(tLis*);
void ListaxProveedor(tLis);
#endif
