#include "cadena.h"
// PRIVADO
void LimpiaBuffer(char c){
	if(c!='\n' && c!=EOF){
		c=getchar();
		LimpiaBuffer(c);
	}
}
void LeeCad(tCad C,int i, int N){
	char c;
	c=getchar();
	if(c!='\n' && c!=EOF && i<N-1){
		C[i]=c;
		LeeCad(C,i+1,N);
	}
	else{
		C[i]='\0';
		LimpiaBuffer(c);
	}
}
// PUBLICO
void CargartCadena(tCad C){
	LeeCad(C,0,Max_Cad);
}
int ComparaCadenas(tCad c1,tCad c2){
	return strcmp(c1,c2);
}
