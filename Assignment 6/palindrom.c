bool isPalindrome(struct ListNode* head){
    
    // pointer for pointing from front
    struct ListNode* temp1 = NULL;
    temp1 = head;
    
    // pointer for pointing from last
    struct ListNode* temp2 = NULL;
    temp2 = head;
    
    int c = 0;
    
    // counting the no of elements
    // for traversing the temp2
    while(temp1->next != NULL) {
        c++;
        temp1 = temp1->next;
    }
    
    int k = 0;
    int i = 0;
    int j = c;
    
    temp1 = head;
    
    // running the loop for half of the elements
    while(k <= c/2) { 
        
        temp2 = temp1;
        
        // placing the temp2 at last elements 
        while(i < j) {
            temp2 = temp2->next;
            i++;
        }
        
        j--;
        
        // compairing the elements 
        // from front and last
        if(temp1->val != temp2->val) {
            return false;
        }
        
        temp1 = temp1->next;
        k++;
        // assigning the i again to k
        i = k;
    }
    
    return true;    

}