// program to fint the rightmost index value 
// of st2 in st1
// Author name - Jashu Bhardwaj
// Date - 02-08-2021

#include <stdio.h>

// function for calculating the length of the string
int length(char str[]) {
    int c = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        c++;
    }
    return c;
}

// function to check the index of st2 in st1
int strindex(char st1[], char st2[]) {
    
    // initially assigning the index -1 
    int index = -1;
    
    // calling length() function to get the length of strings
    int len1 = length(st1);
    int len2 = length(st2);
    for(int i = 0; i < len2; i++) {
        
        index = -1;
        for(int j = i; j < len1; j++) {
            if(st1[len1 - 1 - j] == st2[len2 - 1 - i]) {
                index = len1 - 1 - j;
                break;
            }
        }
    }
    return index;
}

// main function
int main()
{
    char st1[20];
    char st2[10];
    
    // getting strings from user
    printf("Enter first string : ");
    gets(st1);
    printf("Enter second string : ");
    gets(st2);
    
    // calling the function and storing the value
    int index = strindex(st1, st2);
    
    printf("index : %d", index);

    return 0;
}
