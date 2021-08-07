*******************************************************************************/
// program for reversing a string
// Author name - Jashu Bhardwaj
// Date - 27/07/2021

#include <stdio.h>
#include <string.h>

// function for reversing a string
void reverse(char *s) {
    
    char temp;
    int len = strlen(s);
    
    for(int i = 0; i < len/2; i++) {
        
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// main function
int main()
{
    char s[100];
    gets(s);
    
    // calling the reverse function for reversing the string
    reverse(s);
    
    printf("%s",s);

    return 0;
}
