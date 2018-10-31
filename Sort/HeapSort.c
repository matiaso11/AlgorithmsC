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

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
    
    //~ printf("largest, l, r: %d, %d, %d\n", largest, l, r);
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

//~ void printHeap(int arr[]){
	
	//~ int tabLevel = QUANTITY/2;
	//~ int toPrint = 0;
	//~ int level = 1;
	//~ int nrOfPrints = 1;

	
	//~ while(tabLevel >= 0){
		//~ for(int i = 0; i<tabLevel - level + 1; i++){
			//~ printf(" ");
		//~ }
		//~ for(int j = 0; j<nrOfPrints; j++){
			//~ printf("%d", arr[toPrint]);
			//~ toPrint++;
			//~ printf("  "); 
		//~ }
		//~ level++;
		//~ printf("\n");
		//~ tabLevel--;
		//~ nrOfPrints *= 2;
	//~ }
	
//~ }
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); 
	}
	
	printArray(arr);
        
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(&arr[0], &arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
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
	heapSort(tableToSort, QUANTITY);
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("HeapSorting time: %f", cpu_time_used);
	
	printf("\n");
	printf("Sorted array:\n");
	printArray(tableToSort);
	return(0);
}
