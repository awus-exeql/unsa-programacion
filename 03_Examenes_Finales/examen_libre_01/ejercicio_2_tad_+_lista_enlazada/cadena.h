#ifndef CADENA_H
#define CADENA_H

#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

#define Max_Cad 30

typedef char tCad[Max_Cad];

void CargartCadena(tCad);
int ComparaCadenas(tCad,tCad);

#endif
