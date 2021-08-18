#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int top;
    int *Stack;
    int size;
    
} MinStack;

MinStack* minStackCreate() {
    
    MinStack *st = (MinStack*)malloc(sizeof(MinStack*));
    st->top = -1;
    st->size = 100;
    st->Stack = (int*)malloc(sizeof(int) * st->size);
    return st;
    
}

void minStackPush(MinStack* obj, int val) {

    
        obj->top++;
        obj->Stack[obj->top] = val;
    
  
}

void minStackPop(MinStack* obj) {
      
    if(obj->top == -1) {
        return;
    }
    
    else {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
  
    int temp = obj->Stack[obj->top];
    
    return temp;
    
    
}

int minStackGetMin(MinStack* obj) {
  
    int min = obj->Stack[0];
    
    for(int i = 0; i <= obj->top; i++) {
        if(obj->Stack[i] < min) {
            min = obj->Stack[i];
        }
    }
    
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}


int main()
{
    MinStack* obj = minStackCreate();
    
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    
    int temp = 0;
    
    temp = minStackGetMin(obj);
    printf("%d ", temp);  // return -3
     
    minStackPop(obj);
    
    temp = minStackTop(obj);
    printf("%d ", temp); // return 0
        
    temp =  minStackGetMin(obj);
    printf("%d ", temp); // return -2
     

    return 0;
}

