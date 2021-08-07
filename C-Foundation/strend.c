// program to check if st2 is present in st1
//  Author name - Jashu Bhardwaj
// Date - 02/08/2021

#include <stdio.h>

// function for calcuating the string length
int mystrlen(char* st) {
    int c = 0;
    int i = 0;
    while(st[i] != '\0') {
        c++;
        i++;
    }
    return c;
}

// function for checking and returning the index
int strend(char* s, char* t) {
    
    int res = 0;
    int len1 = mystrlen(s) - 1;
    int len2 = mystrlen(t) - 1;
    
    for(int i = 0; i <= len2; i++) {
        
            res = 0;
            if(s[len1 - i] == t[len2 - i]) {
                 res = 1;
            }
        
    }
    
    return res;
}

// main function
int main()
{
    char st1[20];
    char st2[10];
    
    // scanning strings from the user
    printf("Enter first string : ");
    gets(st1);
    printf("Enter second string : ");
    gets(st2);
    
    // calling and storing the index of the string 
    int res = strend(st1, st2);
    
    // printing the index  
    printf("%d", res);

    return 0;
}

