#include <stdio.h>
#include <stdlib.h>

int randomize (int array[], int n) //Gubenko Olesya 112
//funksiya generiruet tcelochislenniy massiv i dubliruet ego (poluchaem dva odinakovikh sgenerirovannih massiva
{
	int i;
	for (i=0; i<n; i++) {
		array[i]=rand()%100+1;
	}
	return 0;
}
