#include <stdio.h>
#include <time.h>

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
