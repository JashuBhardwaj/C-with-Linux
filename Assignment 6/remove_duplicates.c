// program for removing the duplicates in linked list 
// Author name - Jashu Bhardwaj
// Date : 30/08/2021


struct ListNode* deleteDuplicates(struct ListNode* head){

    
    // base case
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *curr = head;
    struct ListNode *prev = curr;
    struct ListNode *res = prev;
    
    // while current in not NULL 
    while(curr != NULL) {
        
        // if current and next element are same then 
        // let current move forward until next is not same
        if(curr->next != NULL && curr->val == curr->next->val) {
            while(curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
           
            // storing the next element adress in previe which is not same
            prev->next = curr->next;
            
        }
        else{
            prev = prev->next;
        }
        // increment the current 
        curr = curr->next;
    }
    return res->next;
}