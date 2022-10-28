#include <stdio.h>

// C Program for iterative binary search.

int itBinarySearch(int *arr, int l, int r, int x){
    while(r >= l){
        int mid = l + (r - l)/2;

        // If element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it
        // can only be present in left subarray
        if (arr[mid] > x)
            r = mid - 1;

        // Else the element can only be present
        // in right subarray
        else
            l = mid + 1;
    }

    return -1;
}

int main(){

    // Test array
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;

    // Function call
    int result = itBinarySearch(arr, 0, sizeof(arr)/4 - 1, x);

    if(result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");

    return 0;
}
