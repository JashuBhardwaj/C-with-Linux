// program to perform strcpy, strcmp, strcat functions
// Author name - Jashu Bhardwaj
// Date - 05-08-2021

#include <stdio.h>

// function to calculate length for the string
int length(char *str) {
    int c = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        c++;
    }
    return c;
}

// function for strcat 
void my_strcat(char *st1, char *st2, int n) {
    
    int len = 0;
    int i;
    int j;
    len = length(st1) + length(st2) + 1;
    char st3[len];
    
    for(i = 0; st1[i] != '\0'; i++) {
        st3[i] = st1[i];
    }
    
    for(j = 0; j < n; j++) {
        st3[j + i] = st2[j];
    }
    
    st3[j + i] = '\0';
    
    st1 = st3;
    printf("%s\n", st3);
    
}

// function for copying st2 in st1
void my_strcpy(char *st1, char *st2, int n) {
    
    
    for(int i = 0; i < n; i++) {
        st1[i] = st2[i];
    }
}

// function for comparing st1 and st2
void my_strcmp(char *st1, char *st2, int n) {
    
    int res = 0;
    int len1 = length(st1);
    for(int i = 0; i < n; i++) {
         res = 0;
        if(st1[i] == st2[i]) {
            res = 1;
        }
    }
    
    if(res == 1) {
        printf("Equal\n");
        
    }
    else {
        printf("Not Equal\n");
    }
}


// main function
int main() {

    char st1[20] = "abcde";
    char st2[20] = "efghi";
    int n = 0;
    
    printf("String 1 : abcde \n String 2 : efghij \n");

    printf("For String Copy \n");
    printf("Enter no of characters you want to copy : ");
    scanf("%d", &n);
    my_strcpy(st1, st2, n);
    
    printf("%s\n", st1);
    
    char st3[20] = "abcde";
    char st4[20] = "efghij";
    
    printf("For String Concatination \n");
    printf("Enter no of characters you want to add : ");
    scanf("%d", &n);
    my_strcat(st3, st4, n);
    
    
    char st5[20] = "abcde";
    char st6[20] = "efghij";
    
    printf("For String Comparison \n");
    printf("Enter no of characters you want to compare : ");
    scanf("%d", &n);
    my_strcmp(st5, st6, n);

    return 0;
}
