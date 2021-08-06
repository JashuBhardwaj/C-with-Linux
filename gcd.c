// program of selection sort using recursion
// Author Name - Jashu Bhardwaj
// Date - 04/08/2021

#include <stdio.h>

// function for calculating gcd of no
int gcd(int a, int b) {
    
    // if a%b gives 0 means it is divisible by b 
    // so b will be the gcd
    if(a % b == 0) {
        return b;
    }
    
    // recursive calling the gcd function 
    // swaping the a and b so this will not repeat 
    gcd(b, a%b);
    
}

// main function
int main()
{
    int a = 0;
    int b = 0;
    
    //entering the no from user
    printf("Enter first no : ");
    scanf("%d", &a);
    printf("Enter second no : ");
    scanf("%d", &b);
    
    // calling and storing the gcd function;
    int gcd_of_no = gcd(a, b);
    
    printf("GCD of no : %d ",gcd_of_no);

    return 0;
}
