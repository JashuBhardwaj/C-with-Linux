/ program for swapping 2 no without third variable
// Author name - Jashu Bhardwaj

#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    
    printf("Enter first no : ");
    scanf("%d", &a);
    
    printf("Enter second no : ");
    scanf("%d", &b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("After Swapping\n");
    printf("First no : %d\n", a);
    printf("Second no : %d", b);

    return 0;
}
