//programma zapolnyaet massiv chislami ot 1 do 100
//sortiruet ih v poryadke vozrastaniya cherez perestanovki indexov
//zameryaet vremya, potrachenoe na sortirovki
#include <stdio.h>
#include <time.h>
#include "my_functions.h"

#define SIZE 4000

int main(void) //Gubenko Olesya 112
{
	int i, a, array[SIZE], ind[SIZE];
	double time, start, end;
	FILE *input_data, *output_data;
	printf("Programma zapolnyaet massiv chislami ot 1 do 100, sortiruet ih v poryadke vozrastaniya cherez perestanovki indexov i zameryaet vremya, potrachenoe na sortirovki.\n");
	//generiruem massiv ili schitivaem massiv is faila
	printf ("If you want to randomize an array press 1, if you want to export the array from the file press 2.\n");
	if ((scanf("%d", &a) !=1)||(a<1)||(a>2))  {
		printf("Unexpectable error, please try again.\n");
		return -1;
	}
	if (a==1) {
		randomize(array, SIZE);
		//esli massiv bil sgenerirovan, raspechativaem ego v file
		input_data = fopen("input_data.txt", "w");
		if (input_data == NULL) {
			printf("File input_data.txt is not opened.\n");
			return -1;
		}
		for (i=0; i<SIZE; i++) {
			fprintf (input_data, "%d ", array[i]);
			if (((i+1)%10)==0)
				fprintf(input_data, "\n");
		}
		fclose(input_data);
	}
	if (a==2)
	{
		if ((input (array, SIZE))!=0)
		return -1;
	}
	//sozdaem massiv indeksov
	for (i=0; i<SIZE; i++)
		ind[i]=i;
	//proizvodim sortirovku obmenami s ispolzovaniem indexov i zameryaem vremya
	start = clock();
	sort_ind(array, ind, SIZE);
	end = clock();
	time = ((end-start)/CLOCKS_PER_SEC);
	//proveryaem chto vse otsortirovalos
	if ((check_array(array, ind, SIZE))==(-1)) {
		printf("Array hasn't been sorted.\n");
		return -1;
	}
	//raspechativaem resultat sortirovki v file
	output_data = fopen("array_sorted.txt", "w");
	if (output_data == NULL) {
		printf("File array_sorted.txt is not opened.\n");
		return -1;
	}
	for (i=0; i<SIZE; i++) {
		fprintf (output_data, "%d ", array[ind[i]]);
		if (((i+1)%10)==0)
			fprintf(output_data, "\n");
	}
	fclose(output_data);
	//vivodim vremya
	printf("Number of elements: %d,\nTime: %lf.\n", SIZE, time);
	return 0;
}
