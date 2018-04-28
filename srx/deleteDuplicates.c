struct *deleteDuplicate(struct ListNode* head){
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
if(head==NULL)return head;
struct ListNode* curr=head;
while(curr->next!=NULL){
    if(curr->val==curr->next->val){
        curr->next=curr->next->next;//重点是如何改变curr->next，制定curr->next为下下个域，略过相同的域，然后继续比较
    }
    else{
        curr=curr->next;//这里两个值不一样，因此不需要改变，curr向后移
    }
}
return head;
}
