#include <stdio.h>

void BubbleSort(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i; j++){
            if(arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void PrintArray(int* arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {46, 24, 33, 10, 2, 81, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    PrintArray(arr, n);

    BubbleSort(arr, n);

    printf("Sorted array: \n");
    PrintArray(arr, n);

    return 0;
}
