// program of selection sort using recursion
// Author Name - Jashu Bhardwaj
// Date - 04/08/2021

#include <stdio.h>

// function for swappint two numbers
void swap(int arr[], int start, int min) {
    int temp = 0;
    temp = arr[start];
    arr[start] = arr[min];
    arr[min] = temp;
}

// function for selection sort
void selection_sort(int arr[], int start, int end) {
    
    if(start >= end) {
        return;
    }
    
    // for finding the index of the min no in array
    int min_index = start;
    
    // finding the min no of the array
    for(int i = start+1; i <= end; i++ ) {
        if(arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    
    // calling the swap function for swapping
    swap(arr, start, min_index);
    
    // recursive call
    selection_sort(arr, start + 1, end);
    
}

// main function
int main()
{
    int arr[] = {5,2,6,1,3,4};
    int start = 0;
    
    // for calculting the size of the array
    int arraySize = sizeof(arr);
    int intSize = sizeof(arr[0]);
    int length = arraySize/intSize;
    int end = length - 1;
    
    // calling the selection sort function
    selection_sort(arr, start, end);
    
    // printing the result array 
    for(int i = 0; i < length; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}

