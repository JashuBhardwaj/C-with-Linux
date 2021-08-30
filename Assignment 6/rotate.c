// program for rotating a linked list k times
// Author name - Jashu Bhardwaj
// Date : 30/08/2021

struct ListNode* rotateRight(struct ListNode* head, int k){

    // base case 
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode *temp = head;
    int c = 1;
    // counting the no of elements
    while(temp->next != NULL) {
        temp = temp->next;
        c++;
        
    }
    // reassingning rotations 
    // because if rotations are greater than no of elements then
    // modulus it to get less rotations to get result
    k = k % c;
    
    // pointing last node to head to make it circular
    temp->next = head;
    
    // we are now calculating the node after which we 
    // have to point to NULL 
    int new_head = c - k;
    
    int i = 1;
    
    // pointing the head to the index for pointing to NULL 
    while(i < new_head) {
        head = head->next;
        i++;
    }
    // pointing temp to head to point temp to NULL
    // head to point to new head
    temp = head;
    head = head->next;
    temp->next = NULL;
    return head;
    
    
}
