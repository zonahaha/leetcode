/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)return false;
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)return true;
    }
    return false;
}
