#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 99
#define QUANTITY 10

int* generateArray()
{
	time_t t;
	static int tableToSort[QUANTITY];
	
	srand((unsigned int) time(&t));
	
	for( int i=0; i<QUANTITY; i++) {
		tableToSort[i] = rand() % RANGE;
	}
	return tableToSort;
}

void printArray(int arr[]) 
{ 
   int i; 
   for (i=0; i < QUANTITY; i++) 
       printf("%d ", arr[i]); 
   printf("\n"); 
} 

void sort(int arr[])
{
	int *countArr;
	countArr = (int*) malloc(RANGE * sizeof(int));
	for(int i = 0; i<RANGE; i++)
	{
		*(countArr+i) = 0;
	}
	
	for(int i = 0; i<QUANTITY; i++)
	{
		countArr[arr[i]]++;
	}
	
	int arrQuantity = 0;
	for(int i = 0; i<RANGE; i++)
	{
		while(countArr[i] > 0)
		{
			arr[arrQuantity] = i;
			arrQuantity++;
			countArr[i]--;
		}
	}
	
	free(countArr);
}

int main(){
	
	clock_t start, end;
	double cpu_time_used;
	
	int *tableToSort;
	
	tableToSort = generateArray();
	//printf("Array to sort:\n");
	//printArray(tableToSort);
	//printf("\n");
	
	start = clock();
	sort(tableToSort);
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("CoutingSorting time: %f", cpu_time_used);
	
	//printf("\n");
	//printf("Sorted array:\n");
	//printArray(tableToSort);
	return(0);
}
