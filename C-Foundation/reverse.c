#include <stdio.h>

void reversal_process(int arr[], int n) {

    int temp = 0;
    
    for(int i = 0; i < n/2; i++) {

        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;

    }

}

int main() {

    int n = 0;
    printf("Enter no of elements \n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Elements \n");

    for(int i = 0; i < n; i++) {

        scanf("%d",&arr[i]);
    }

    reversal_process(arr, n);
 
    for(int i = 0; i < n; i++) {

        printf("%d ",arr[i]);
    }   


    return 0;
}