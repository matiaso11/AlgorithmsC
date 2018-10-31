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
		tableToSort[i] = rand() % RANGE  + 1;
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
	int i, key, j; 
	for (i = 1; i < QUANTITY; i++) 
	{ 
		key = arr[i]; 
		j = i-1; 

		/* Move elements of arr[0..i-1], that are 
		  greater than key, to one position ahead 
		  of their current position */
		while (j >= 0 && arr[j] > key) 
		{ 
		   arr[j+1] = arr[j]; 
		   j = j-1; 
		} 
		arr[j+1] = key; 
		
		//printf("%d. ", i);
		//printArray(arr);
	} 
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
	printf("InsertionSorting time: %f", cpu_time_used);
	
	//printf("\n");
	//printf("Sorted array:\n");
	//printArray(tableToSort);
	return(0);
}
