struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    // base cases 
    if(n == 1 && head->next == NULL) {
        head = NULL;
        return head;
    }
    
    struct ListNode *temp = head;
    int c = 0;
    
    // counting the no of elements
    while(temp != NULL) {
        c++;
        temp = temp->next;
    }
   
    // index of the element to remove;
    // adding 1 to it because n is from last , 
    // so now it pointf to index from first
    int index = n + 1;
    
    
    temp = head;
    // when index is greater than element count , 
    // it means to remove element from front , 
    // so shift the head forward and element is removed
    if(c < index) {
        temp = temp->next;
        head = temp;
        return head;
    }
    
    // when element count is greater than the index,
    // move the pointer to element before that element
    while(c > index) {
        temp = temp->next;
        c--;
    } 

    // check if next to next element is NULL or not
    // if not then point to that element
    if(temp->next->next != NULL) {
        temp->next = temp->next->next;
    }
    // else point to NULL
    else {
        temp->next = NULL;
    }
    
    return head;
    
}