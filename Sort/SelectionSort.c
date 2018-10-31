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
	int min = 0;
	for(int c = 0; c<QUANTITY-1; c++)
	{
		min = c;
		for(int d = c + 1; d<QUANTITY; d++)
		{
			if(arr[d]<arr[min])
			{
				min = d;
			}	
		}
		if(min != c)
		{
			int swap = arr[c];
			arr[c] = arr[min];
			arr[min] = swap;
		}
		//printf("%d. ", c);
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
	printf("SelectionSorting time: %f", cpu_time_used);
	
	//printf("\n");
	//printf("Sorted array:\n");
	//printArray(tableToSort);
	return(0);
}
