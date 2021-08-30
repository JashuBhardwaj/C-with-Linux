#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void add_head(struct Node **head) {
    struct Node *ptr = NULL;
    ptr = (struct Node*)malloc(sizeof(struct Node*));
    
    int n = 0;
    printf("Enter Value : ");
    scanf("%d", &n);
    
    if(*head == NULL) {
        ptr->data = n;
        ptr->next = NULL;
        ptr->prev = NULL;
        *head = ptr;
        return;
    }
    
    ptr->data = n;
    (*head)->prev = ptr;
    ptr->next = *head;
    ptr->prev = NULL;
    *head = ptr;
}

void add_tail(struct Node **head) {
    int n = 0;
    printf("Enter Value : ");
    scanf("%d", &n);
    struct Node *ptr = NULL;
    ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr->data = n;
    
    if(*head == NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        *head = ptr;
        return;
    }
    
    struct Node *temp = *head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    ptr->prev = temp;
    
}

void remove_head(struct Node **head) {
    if(*head == NULL) {
        printf("Underflow\n");
        return;
    }
    
    struct Node *temp = *head;
    
    if(temp != NULL && temp->next == NULL) {
        printf("Element removed from head : %d\n", temp->data);
        temp = NULL;
        *head = temp;
        return;
    }
    printf("Element removed from head : %d\n", temp->data);
    temp = temp->next;
    temp->prev = NULL;
    *head = temp;
    
}

void remove_tail(struct Node **head) {
    if(*head == NULL) {
        printf("Underflow\n");
        return;
    }
    
    struct Node *temp = *head;
    
    if(temp != NULL && temp->next == NULL) {
        printf("Element removed from tail : %d\n", temp->data);
        temp = NULL;
        *head = temp;
        return;
    }
    
    struct Node *curr = *head;
    
    while(curr->next != NULL) {
        
        curr = curr->next;
    }
    printf("Element removed from tail : %d\n", curr->data);
    curr = curr->prev;
    curr->next = NULL;
}

void display(struct Node *head) {

    struct Node *temp = head;
    while(temp != NULL) {
        printf("     %d     \n", temp->data);
        temp = temp->next;
    }

}

void peek_head(struct Node **head) {
    if(*head == NULL) {
        printf("NULL\n");
    }
    printf("Peek Head : %d\n", (*head)->data);
}

void peek_tail(struct Node **head) {
    struct Node *temp = *head;
    
    if(temp == NULL) {
        printf("NULL\n");
    }
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Peek Tail : %d\n", temp->data);
    
    
}

void check_presence(struct Node *head) {
    int n = 0;
    
    printf("Enter element to search : ");
    scanf("%d", &n);
    
    struct Node *temp = head;
    
    if(temp->data == n) {
        printf("Present\n");
        return;
    }
    
    while(temp->next != NULL) {
        if(n == temp->data) {
            printf("Present\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not Present\n");
}


int main() {
    struct Node *head = NULL;
    
    int ch = 0;
    
    do{
    
        printf("Enter your choice :\n");
        printf("-----------------\n");
        printf("1. Add element at head \n2. Add element at tail \n3. Remove element from head \n4. Remove element from tail \n5. Display \n6. Peek Head \n7. Peek Tail \n8. Check Presence \n9. Exit \n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                add_head(&head);
                break;
            case 2:
                add_tail(&head);
                break;
            case 3:
                remove_head(&head);
                break;
            case 4:
                remove_tail(&head);
                break;
            case 5:
                display(head);
                break; 
            case 6:
                peek_head(&head);
                break;
            case 7:
                peek_tail(&head);
                break;
            case 8:
                check_presence(head);
                break;
                

        }

    } while(ch != 9);
    
    
    return 0;
}