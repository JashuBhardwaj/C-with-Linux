// program to fint the index of str2 in str1
//  Author name - Jashu Bhardwaj
// Date - 02/08/2021

#include <stdio.h>

// function for returning the index
// if char of st2 is present in st1
// returning -1 if not present
int any(char* s1, char* s2) {
    
    
    for(int i = 0; s2[i] != '\0'; i++) {
        for(int j = 0; s1[j] != '\0'; j++) {
            if(s1[j] == s2[i]) {
                return j;
            }
        }
    }
    
    return -1;
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
    int index = any(st1, st2);
    
    // printing the index  
    printf("%d", index);

    return 0;
}
