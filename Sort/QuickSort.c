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

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high);
        
        //printArray(arr); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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
	quickSort(tableToSort, 0, QUANTITY-1);
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("QuickSorting time: %f", cpu_time_used);
	
	//printf("\n");
	//printf("Sorted array:\n");
	//printArray(tableToSort);
	return(0);
}
