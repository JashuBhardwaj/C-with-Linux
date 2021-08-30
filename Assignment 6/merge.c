// program for merging two linked list in assending order
// Author name - Jashu Bhardwaj
// Date : 29/08/2021


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    // if l1 is NULL then return l2
    if(l1 == NULL) {
        return l2;
    }
    // if l2 is NULL then return l1
    if(l2 == NULL) {
        return l1;
    }
    
    // if l1->value is less than l1
    if(l1->val < l2->val) {
        // recursively calling the merge function
        // and storing the address of next small element after l1 
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
         // recursively calling the merge function
        // and storing the address of next small element after l2
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    
}