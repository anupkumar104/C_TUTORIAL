#include <stdio.h>
#include <limits.h>
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0, k = p;
    while (k <= r) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
}
void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  
        merge_sort(A, p, q); 
        merge_sort(A, q + 1, r); 
        merge(A, p, q, r);   
    }
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
    int size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int A[size]; 
    printf("Enter the elements: ");  
    for (i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
    printf("Unsorted array:\n");
    printArray(A, size);
    merge_sort(A, 0, size - 1);
    printf("Sorted array: \n");
    printArray(A, size);
    return 0;
}