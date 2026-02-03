/*
	Un Observatorio Espacial opera con una lista generada por su telescopio, de cada observacion se 
lleva la siguiente informacion: Codigo, Fecha(aaaammdd), Hora(hhmmss), Coordenada espacial(xxxyyyzzz) 
y Anomalia[1: Colision de cuerpos; 2: Estrella; 3: Meteorito o 4: Energia luminica].
	Se solicita crear un programa convenientemente modularizado que, utilizando Lista Simplemente 
Enlazada, permita cargar la lista de N observaciones, las que se ordenaran por codigo, a medida 
que se ingresan los registros. Posteriormente eliminar los registros cuya fecha coincide con un mes 
y año dado. Por ultimo, mostrar la lista resultante.
*/
#include <stdio_ext.h>
#include <stdlib.h>
typedef struct{
	int cod,anlia;
	long fecha,hora,coords;
}tObs;
typedef struct nodo{
	tObs obs;
	struct nodo* sig;
}tNodo;
typedef tNodo* tList;
// PROTOTIPOS DE FUNCIONES
tObs GeneraObs();
void MostrarObs(tObs);
int main(void){
	
	return 0;
}
