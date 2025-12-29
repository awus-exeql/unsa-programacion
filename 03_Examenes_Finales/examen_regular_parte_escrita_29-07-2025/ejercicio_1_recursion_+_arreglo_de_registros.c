/*Un Biologo que trabaja en una reserva natural de argentina, lleva una lista de
los animales que captura de la reserva para estudiarlos. A cada animal se le agrega
un rastreador satelital al devolverlos a su habitat. De cada animal lleva la siguiente
informacion: Codigo (Numerico), Nombre vulgar, Tipo (Ave, Mamifero, Reptil, Pez),
Peso (Numerico), Edad (Numerico).

Se requiere un programa que utilizando Recursividad y TD arreglo de registros permita,
ingresar la lista de N animales estudiados, posteriormente se ordenará la misma por
el campo Codigo utililizando el metodo QSort. Luego presentar un menu con las siguientes
opciones:
	a) Dada una edad ingresada por teclado, crear y mostrar una nueva lista con los animales
	que tienen la misma "Edad".
	b) Dado un Nombre vulgar informar cuantos animales de esta especie se han estudiado.*/
#include <stdio.h>

#define Max_Cad 20
#define Max_List 30
typedef char TCad[Max_Cad];
typedef struct{
	int codigo,tipo,edad;
	float peso;
	TCad nombre;
}TAnimal;
typedef TAnimal TVec[Max_List];
int main(void){
	
	return 0;
}
