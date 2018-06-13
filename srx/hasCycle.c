/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
////////////////////////////////////////////////////这里用的是快慢指针算法
/////////////////////////////////////////////////如果存在环，慢指针总会追上快指针，无论奇偶数，可以画个图试试
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
