// program for printing star pattern
// Author name - Jashu Bhardwaj
// Date - 27/07/2021

#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter the no of rows\n");
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++) {
        
        for(int k = 0; k <= n-i; k++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            printf("# ");
        }
        printf("\n");
    }

    return 0;
}
