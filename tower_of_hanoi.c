// program to demonstrate TOWER OF HANOI
//  Author name - Jashu Bhardwaj
// Date - 04/08/2021

#include <stdio.h>

// functio to print the moment of disc
void move(char from, char to) {
    printf("Move disc from %c to %c \n", from, to);
}

// function for tower of hanoi disc movement
void tower_of_hanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        move(from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move(from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}


// main function
int main()
{
    // calling the function
    tower_of_hanoi(3,'A','C','B');
    return 0;
}


