#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void is_empty(struct node *head) {

    if(head == NULL) {
        printf("Empty\n");
    }
    else {
        printf("Not Empty\n");
    }
}

void push(struct node **head) {

    int n = 0;
    printf("Enter Value : ");
    scanf("%d", &n);

    struct node *ptr = NULL;
    ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->data = n;
    ptr->next = *head;
    *head = ptr;
    

    /*

    if(*head == NULL) {
    
        *head = ptr;
    }
    else {

        struct node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    
    }

    */

}

void pop(struct node **head) {

    struct node *ptr = *head;
    int item = 0;
    item = ptr->data;
    
    printf("Element popped : %d\n", item);
    ptr = ptr->next;
    *head = ptr;
}


void display(struct node **head) {

    struct node *temp = *head;
    while(temp->next != NULL) {
        printf("     %d      \n", temp->data);
        temp = temp->next;
    }
    
}

void check_Empty(struct node *head) {

    if(head == 	NULL) {
        printf("Empty\n");
    }
    else {
        printf("Not Empty\n");
    }
}

void top(struct node **head) {
    struct node *temp = *head;
    
    printf("Top : %d\n", temp->data);
}

int main ()
{
    struct node *head = NULL;
    //head = (struct node*)malloc(sizeof(struct node*));

    int ch = 0;

    do{
    
        printf("Enter your choice :\n");
        printf("-----------------\n");
        printf("1. Push \n2. Pop \n3. Display \n4. Top \n5. Is_Empty \n6. Exit \n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push(&head);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                top(&head);
                break;
             case 5:
                 check_Empty(head);
                 break;        

        }

    } while(ch != 6);


    return 0;
}
