#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
	int *bocketsArr;
	bocketsArr = (int*) malloc(RANGE * sizeof(int));
	memset(bocketsArr, 0, RANGE * sizeof(int));
	for(int i = 0; i<QUANTITY; i++)
	{
		bocketsArr[i]++;
	}

	printf("\n%lu\n", sizeof(bocketsArr)/sizeof(int));

	int arrQuantity = 0;
	for(int i = 0; i<RANGE; i++)
	{
		while(*(bocketsArr+i) > 0)
		{
			arr[arrQuantity] = i;
			arrQuantity++;
		}
	}

	free(bocketsArr);
}

int main(){

	int *tableToSort;

	tableToSort = generateArray();
	printf("Array to sort:\n");
	printArray(tableToSort);
	printf("\n");

	sort(tableToSort);

	printf("\n");
	printf("Sorted array:\n");
	printArray(tableToSort);

	return(0);
}
