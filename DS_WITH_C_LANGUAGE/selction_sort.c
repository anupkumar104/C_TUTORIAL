#include <stdio.h>

// User-defined function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// User-defined function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part
        minIndex = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        
        // Swap the found minimum element with the first element
        swap(&arr[minIndex], &arr[i]);
    }
}

// User-defined function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    
    // User input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    // User input for array elements
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: \n");
    printArray(arr, n);
    
    // Sorting the array using Selection Sort
    selectionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}