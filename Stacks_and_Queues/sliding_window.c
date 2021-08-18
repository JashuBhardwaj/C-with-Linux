#include <stdio.h>


typedef Astruct{
  
    int front;
    int rear;
    int size;
    int *q;
    
} Queue;

Queue* createQueue(int k) {
    
    Queue *st = (Queue*)malloc(sizeof(Queue*));
    st->front = -1;
    st->rear = -1;
    st->size = k;
    st->q = (int*)malloc(sizeof(int*));
    return st;
} 



int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

}


int main()
{
   int arr[8] = {1,3,-1,-3,5,3,6,7};
   
   int numSize = 8;
   int k = 3;
   
   
   

    return 0;
}

