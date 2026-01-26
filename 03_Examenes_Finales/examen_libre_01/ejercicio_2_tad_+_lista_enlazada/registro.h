#ifndef REGISTRO_H
#define REGISTRO_H

#include "cadena.h"

typedef struct{
	int cod,cantd;
	tCad nomar,nompr;
	long fecha;
	float precio;
}tArt;

tArt GeneratArt();
void MostrartArt(tArt);
int CompxNompr(tArt,tArt);
int GetCodigo(tArt);
int ComptArtcontCadxNpr(tArt,tCad);
#endif
