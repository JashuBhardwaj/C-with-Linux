#include <stdio.h>

int bitAnd (int x, int y) {
     return (~( ~x | ~y));
}

int bitXor (int x, int y) {
     return ( ~x & y);
}

int sign(int n) {
    
    if(!n == 1) {
        return 0;
    }
    else if((n & (1 << 31)) == 0) {
        return 1;
    }
     
    else {
        return -1;
    }
}

int logicalShift(int x, int n) {
    return (x>>n)&~(((1<<31)>>n)<<1);
    
}

int bang(int x) {

  int minus_x = ~x+1;

  int bits = (minus_x | x) >> 31; 
  return bits + 1;
}


int main()
{
    printf("bitAnd : %d\n", bitAnd(6,5));
    
    printf("BitXor : %d\n", bitXor(4,5));
    
    int res = sign(-6);
    if(res == 1) {
        printf("Sign : Positive\n");
    }
    else if(res == -1) {
        printf("Sign : Negative\n");
    }
    else {
        printf("Sign : Zero\n");
    }
    
    printf("LogicalShift : %d\n", logicalShift(0x87654321, 4));
    
    printf("Bang : %d\n", bang(4));

    return 0;
}
