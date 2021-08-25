#include <stdio.h>

int merge(int arr[], int s, int mid, int end) {
    
   int k = s, i = s, j = mid + 1;
    int inversionCount = 0;
    
    int temp[end - s + 1];
 
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }
 
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    for (int i = s; i <= end; i++) {
        arr[i] = temp[i];
    }
 
    return inversionCount;
    
    
}
    
int merge_sort(int arr[], int s, int end) {
    
    if(s <= end) {
        
        int mid = (s + mid)/2;
    int c = 0;
    c += merge_sort(arr, s, mid);
    c += merge_sort(arr, mid + 1, end);
    
    c += merge(arr, s, mid, end);
    
    return c;
       
    }
    
    
}




int main()
{
    int arr[] = {8,4,2,1};
    
    int s = 0;
    int end = sizeof(arr)/sizeof(arr[0]);
    
    int c = merge_sort(arr, s, end - 1);
    
    
    
    for(int i = 0; i < end; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    printf("%d", c);


    return 0;
}

