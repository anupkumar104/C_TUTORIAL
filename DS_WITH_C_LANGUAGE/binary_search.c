#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {

    if (left > right) {
        return -1; 
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }
    return binarySearch(arr, mid + 1, right, target);
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
    printf("%d ", arr[i]);
    }
    }
int main() {
   int n, i,target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter the elements: ");  
    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("enter target:\n");
    scanf("%d",&target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
