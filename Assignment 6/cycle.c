// program for linked list cycle to return the starting point of cycle
// Author name - Jashu Bhardwaj
// Date : 28/08/2021

struct ListNode *detectCycle(struct ListNode *head) {
    
    
    // base case 
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // slow increaments by 1
    slow = slow->next;
    
    // fast increaments by 2
    fast = fast->next->next;
    
    // if fast and fast->next is not NULL
    while(fast != NULL && fast->next != NULL) {
        
        if(slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // if not same means NULL
    if(slow != fast) {
        return NULL;
    }
    
    // reassigning slow to head
    slow = head;
    
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
    
}
