#include <stdio.h>
#define Max_List 7
typedef int TArreglo[Max_List];
int main(void) {
	TArreglo A={3,-5,2,0,7,-2};
	TArreglo C={'a','e','i','o','u','b','c'};
	int i;
	for(i=0;i<6;i++){
		if(i%2==0)
			printf("\nA[%d]=%d",i,A[i]);
		else
			printf("\nC[%d]=%c",i,C[i]);
	}
	return 0;
}
