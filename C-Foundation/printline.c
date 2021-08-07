#include <stdio.h>

#define MAXLEN 1000
#define MINLEN 80

int main(void)
{
    int min = 80;
    int max = 1000;
    int c;
    int index = 0;
    char line[max];

    while ((c = getchar()) != EOF)
    {
        if (c != '\n')
        {
            line[index] = c;
            ++index;
        }

        else
        {
            line[index] = '\0';

            if (index >= min)
            {
                printf("%s\n", line);
            }
            index = 0;
        }
    }

    return 0;
}