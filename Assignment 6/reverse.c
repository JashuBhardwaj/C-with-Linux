// program for reversing the elements from left to right in linked list
// Author name - Jashu Bhardwaj
// Date : 30/08/2021

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
    int c = 0;
    int i = 0 , j = 0, temp, k;
    
    struct ListNode *leftnode = head;
    struct ListNode *rightnode = head;
    
    // pointing leftnode to the element on index left
    while(i < left - 1) {
        leftnode = leftnode->next;
        i++;
    }
    
    // assigning index values of elements
    // from where we have to swap till where
    i = left - 1;
    j = right - 1;
    
    // loop to run till left is less than right
    while(i < j) {
        
        k = 0;
        
        // pointing to the element on the index right
        while(k < j) {
            rightnode = rightnode->next;
            k++;
        }
        
        // swapping the values using third variable
        temp = leftnode->val;
        leftnode->val = rightnode->val;
        rightnode->val = temp;
        
        // increment left pointer 
        leftnode = leftnode->next;
        
        // reassigning right pointer to head for traversing
        rightnode = head;
        i++;
        j--;
        
    }
    
    return head;
    
}