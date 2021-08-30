#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **head) {

    int n = 0;
    printf("Enter value : ");
    scanf("%d", &n);

    struct node *ptr = NULL;
    ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = n;
    
    ptr->next = *head;
    *head = ptr;

}

void dequeue(struct node **head) {

    if(*head == NULL) {

        printf("Underflow\n");
        return;
    }
    struct node *temp = *head;
    if(temp != NULL && temp->next == NULL) {
        printf("Element Dequeued : %d\n", temp->data);
        temp = NULL;
        *head = temp;
        return;
    }

    struct node *prev = NULL;
    struct node *curr = *head;
    
    while(curr->next != NULL) {

        prev = curr;
        curr = curr->next;   

    }
    
    printf("Element Dequeued : %d\n", curr->data);
    
    prev->next = NULL;
    
}

void check_Empty(struct node *head) {

    if(head == NULL) {
        printf("Empty\n");
    }
    else {
        printf("Not Empty\n");
    }

}

void peek(struct node **head) {
    
    if(*head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("Peek : %d\n", (*head)->data);

}

void display(struct node **head) {

    struct node *temp = *head;
    while(temp != NULL) {
        printf("     %d     \n", temp->data);
        temp = temp->next;
    }

}


int main ()
{
    struct node *head = NULL;

    int ch = 0;

    do{
    
        printf("Enter your choice :\n");
        printf("-----------------\n");
        printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Peek \n5. Is_Empty \n6. Exit \n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                enqueue(&head);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                peek(&head);
                break;
             case 5:
                 check_Empty(head);
                 break;        

        }

    } while(ch != 6);


    return 0;
}
