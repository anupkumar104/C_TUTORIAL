#include <stdio.h>
void insertionsort(int arr[], int n) {
 int i, j, key;
 for ( j = 1; j < n ;j++){
    key=arr[j];
    i=j-1;
    while(i >= 0 && arr[i]>key){
     arr[i+1]=arr[i];
     i = i - 1;
    }
    arr[i+1]=key;   
 }
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
    printf("%d ", arr[i]);
 }
    printf("\n");
}
int main(){
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter the elements: ");  
    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("Unsorted array:\n");
    printArray(arr, n);
    insertionsort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}