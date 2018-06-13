/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//////////////////////////////////////////////////这里用的是快慢指针算法
/////////////////////////////////////////////////如果存在环，当快指针走到最后一个节点也就是环的起始节点，此时慢指针追上快指针
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
