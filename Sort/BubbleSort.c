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

void sort(int array[])
{
	int noSwap = 1;
	for (int c = 0 ; c < QUANTITY - 1; c++)
	{
		noSwap = 1;
		for (int d = 0 ; d < QUANTITY - c - 1; d++)
		{
			if (array[d] > array[d+1]) /* For decreasing order use < */
			{
				int swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
				noSwap = 0;
			}
		}
		if(noSwap)
		{
			printf("No more swaps \n");
			break;
		}
		
		//printf("%d. ", c);
		//printArray(array);
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
	printf("BubbleSorting time: %f", cpu_time_used);
	
	//printf("\n");
	//printf("Sorted array:\n");
	//printArray(tableToSort);
	return(0);
}
