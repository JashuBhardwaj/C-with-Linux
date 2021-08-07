#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_vowels(char str[]) {

    int vowels = 0;
    int consonants = 0;
    int i;
    char ch;

    for(i = 0; str[i] != '\0'; i++) {

        ch=str[i];

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) {

            vowels++;

        }

        else if(ch == ' ' || ( ch >='a' && ch <='z' ) || ( ch >= 'A' && ch <='Z' ) ) {

                consonants++;

        }

    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

}

int main() {

    char str[50];
    printf("Enter String: ");
    fgets(str, sizeof(str), stdin);
    count_vowels(str);


    return 0;


}
