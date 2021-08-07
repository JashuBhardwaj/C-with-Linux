// program to check if the string is palindrome or not
// Author name - Jashu Bhardwaj
// Date - 28/07/2021

#include <stdio.h>
#include <string.h>

// function to check if the string is palindrom or not
// it returns 0 if its not palindrom else returns 1
int check_palindrome(char *str) {
    
    // end to addressing the last index
    int end = strlen(str) - 1;
    int s = 0;
    
    // compairing the starting and end characters
    while(s <= end) {
        if(str[s] == ' ') {
            s++;
            continue;
        }
        if(str[end] == ' ') {
            end--;
            continue;
        }
        if(str[s] != str[end]) {
            return 0;
        }
        s++;
        end--;
    }

    return 1;    
    
}

// converting the string to lower case only
void convert(char *str) {
    
    for(int i = 0; str[i] != '\0'; i++) {
        
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

// main function
int main()
{
    char str[100];
    gets(str);
    
    // calling the function to convert the string in lower case
    convert(str);
    
    // storing the result 
    int res = check_palindrome(str);
    
    if(res == 1) {
        printf("True");
        
    }
    else 
    {
        printf("False");
    }

    return 0;
}
