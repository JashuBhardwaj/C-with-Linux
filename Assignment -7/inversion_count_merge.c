#include <stdio.h>

void merge(int arr[], int s, int mid, int end) {
    
    int i = s;
    int j = mid + 1;
    int n = end - s + 1;
    int left[n];
    
    int k = 0;
    
    while(i <= mid && j <= end) {
        if(arr[i] > arr[j]) {
            arr2[k++] = arr[j++];
        }
        else {
            arr2[k++] = arr[i++];
        }
    }
    
    while(i <= mid) {
        arr2[k++] = arr[i++];
    }
    
    while(j <= mid) {
        arr2[k++] = arr[j++];
    }
    
    for(i = 0; i < n; i++){
        arr[s + i] = arr2[i];
    }
    
}

void merge_sort(int arr[], int s, int end) {
    
    if(s >= end) {
        return;
    }
    
    int mid = (s + mid)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, end);
    
    merge(arr, s, mid, end);
}




int main()
{
    int arr[4] = {8,4,2,1};
    
    int s = 0;
    int end = 4 - 1;
    
    merge_sort(arr, s, end);
    
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}
