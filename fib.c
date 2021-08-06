// program to print the n no from the series
// which are at 3rd positions
// Author name - Jashu Bhardwaj
// Date - 05/08/2021

#include <stdio.h>

// function for making fibbonacci series
void fib(int n) {
    
    // base case
    if(n == 0) {
        return;
    }
    static int i = 1;
    static int a = 1;
    static int b = 1;
    
    if(i % 3 == 0){
        printf("%d ", a);
        n--;
    }
    
    int temp = 0;
    
    // shifting the values of a and b
    temp = a;
    a = b;
    b = temp + b;
    
    
    i++;
    fib(n);
    
}

// main function
int main()
{
    int n = 0;
    printf("Enter the no of digits to print from series : ");
    scanf("%d", &n);
    
    fib(n);

    return 0;
}

