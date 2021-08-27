#include <stdio.h>
#include <string.h>

void squeeze_1(char st1[], char st2[]) {

    int i, j, k;

    for(k = 0; st2[k] != '\0'; k++) {
 
        for(i = 0, j = 0; st1[i] != '\0'; i++) {

            if(st1[i] != st2[k]) {

                st1[j++] = st1[i];
            }

        }

        st1[j] = '\0';

    }


}



int main() {

    char st1[20], st2[20];
    printf("Enter String1: ");
    gets(st1);
    printf("Enter String2: ");
    gets(st2);
    
    squeeze_1(st1, st2);
    printf("%s", &st1);
    return 0;

}