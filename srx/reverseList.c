/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {///////////别人家的递归
    if(!head->next||!head)return head;//head->next重点
    struct ListNode* res=malloc(sizeof(struct ListNode));
    if(head->next)res=reverseList(head->next);
    head->next->next=head;//////重点
    head->next=NULL;   ///////重点
    return res;
}
/////////////////////////////////////////////////////////
struct ListNode* reverseList(struct ListNode* head) {//依然是别人家的循环
  if(!head)return NULL;
    struct ListNode*p=head,*q=head->next,*r;
    while(q){/////////////把这四部看懂    也可以这么写struct ListNode *p,*q,*r;  p=head;q=head->next;
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head->next=NULL;
    return p;
}
