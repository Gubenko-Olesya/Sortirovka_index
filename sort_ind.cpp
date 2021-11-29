#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//sortirovka indexami
int sort_ind(int array[], int ind[], int n) //Gubenko Olesya 112
{
	int i, j, k, ind_min, buf;
	for(i=0; i<n; i++) {
		ind_min=ind[i];
		//sredi elementov bolshih vzyatogo po poryadku ishem minimalniy i zapominaem ego index
		for(j=(i+1); j<n; j++) {
			if (array[ind[j]]<array[ind_min]) {
				ind_min=ind[j];
				k=j;
			}
		}
		//obmenivaem index minimalnogo na bivshiy index
		buf=ind[i];
		ind[i]=ind_min;
		ind[k]=buf;
	}
	return 0;
}


/*	for(i=0; i<SIZE; i++) {
		min=array1[i];
		ind_min=i;
		for(j=(i+1); j<SIZE; j++) {
			if (array1[j]<min) {
				min=array1[j];
				ind_min=j;
			}
		}
		buf=array1[i];
		array1[i]=min;
		array1[ind_min]=buf;
	}
	return 0;
}
*/
