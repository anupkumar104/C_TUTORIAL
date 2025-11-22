#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}
void printArray(int A[], int n){
    for (int i = 0; i < n; i++){
    printf("%d ", A[i]);
 }
    printf("\n");
}
void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n]; 
    printf("Enter the elements: ");  
    for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
    printf("Unsorted array:\n");
    printArray(A, n);
    quicksort(A, 0, n - 1);
     printf("Sorted array:\n");
    printArray(A, n);
    return 0;
}