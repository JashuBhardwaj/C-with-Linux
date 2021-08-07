// program to convert hexadecimal to decimal no
// Author name - Jashu Bhardwaj
// Date - 02-08-2021

#include <stdio.h>

// function to find square root of a no
int squareroot(int base, int k) {
    
    if(k == 0) {
        return 1;
    }
    
    if(k == 1) {
        return base;
    }
    
    while(k > 1) {
        base *= base;
        k--;
    }
    
    return base;
}

// function to convert the no from string to int
int getnum(char ch) {
    
    int num = 0;
    
    if(ch >= '0' && ch <= '9') {
        num = ch - '0';
        
    }
    else{
        switch(ch) {
        
        case 'A':
        case 'a':
            num = 10;
            break;
        case 'B':
        case 'b':
            num = 11;
            break;
        case 'C':
        case 'c':
            num = 12;
            break;    
        case 'D':
        case 'd':
            num = 13;
            break;
        case 'E':
        case 'e':
            num = 14;
            break;
        case 'F':
        case 'f':
            num = 15;
            break; 
        default:
            num = 0;
    }
        
    }
    
    return num;
    
}

// function to convert hexadecimal to decimal 
// and return the value
int htio(char ch[], int len) {
    
    int sum = 0;
    int sqre = 0;
    int k = 0;
    int no = 0;
    int base = 16;
    for(int i = 0; ch[i] != '\0'; i++) {
        no = getnum(ch[len-1-i]);
        sqre = squareroot(base, k);
        sum = sum + no*sqre;
        k++;
    }
    
    return sum;
    
}

// function to calculate length of the string
int length(char ch[]) {
    int c = 0;
    for(int i = 0; ch[i] != '\0'; i++) {
        c++;
    }
    
    return c;
}

// main function
int main()
{
    char ch[20];
    
    // getting the hexadecimal no from user
    printf("Enter hexadecimal no : ");
    gets(ch);
    
    // calling length function for getting
    // length of string
    int len = length(ch);
    
    // getting the decimal no
    int no = htio(ch, len);
    printf("Decimal : %d\n",no);
    

    return 0;
}


 


