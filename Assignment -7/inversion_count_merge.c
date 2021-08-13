#include <stdio.h>

int merge_sort(int arr[], int s, int end) {
    if(s >= end) {
        return 0;
    }
    
    int mid = (s + end) / 2;
    
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, end);
    
    int c = 0;
    
    c += merge(arr, s, mid, end);
    
    return c;
}

int merge(int arr[], int s, int mid, int end) {
    
    int i = 0;
    int j = 0;
    int c = 0;
    
    int arr2[end + 1];
    int k = end;
    i = s;
    
    j = mid + 1;
    
    while(i >= mid || j >= end) {
        if(arr[i] > arr[j]) {
            c++;
            arr2[k] = arr[i];
            i++;
            k--;
            
        }
        
        else {
            arr2[k] = arr[j];
            j++;
            k--;
        }
    }
    
    while(i >= mid) {
        arr2[k] = arr[i];
        i++;
        k--;
    }
    
    while(j >= end) {
        arr2[k] = arr[j];
        j++;
        k--;
    }
    
    for(i = s; i <= end; i++) {
        arr[i] = arr2[j];
        
    }
    
    return c;
    
    
}

int main()
{
    int n = 0;
    
    printf("Enter Array size : ");
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int s = 0;
    
    int end = n - 1;
    
    int count = merge_sort(arr, s, end);
    
    printf("%d", count);
    
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}
