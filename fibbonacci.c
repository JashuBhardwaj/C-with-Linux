#include <stdio.h>

void fib(int n) {
    
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
    
    temp = a;
    a = b;
    b = temp + b;
    
    
    i++;
    fib(n);
    
}

int main()
{
    int n = 0;
    printf("Enter the no of digits to print from series : ");
    scanf("%d", &n);
    
    fib(n);

    return 0;
}
