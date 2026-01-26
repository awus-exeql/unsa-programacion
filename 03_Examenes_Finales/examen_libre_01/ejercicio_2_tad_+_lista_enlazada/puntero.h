#ifndef PUNTERO_H
#define PUNTERO_H

#include "registro.h"

typedef struct nodo{
	tArt reg;
	struct nodo* sig;
}tNodo;

typedef tNodo* tPtr;

tPtr CrearNodo();
void CargaOrdenado(tPtr*,tPtr);
void MostrartPtr(tPtr);
int GetCodigoxtPtr(tPtr);
void EliminarNodoxCod(tPtr*,int);
void MostrarxProveedor(tPtr,tCad);
#endif
