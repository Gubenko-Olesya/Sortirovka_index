#include <stdio.h>

int check_array(int array[], int ind[], int n) //Gubenko Olesya 112
//funksiya proveryaet, otsortirovalsya li massiv
{
	int i;
	for (i=0; i<(n-1); i++) {
		if (array[ind[i]]>array[ind[i+1]])
			return -1;
	}
	return 0;
}
