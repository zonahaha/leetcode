/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* a=headA;
    struct ListNode* b=headB;
    if(!a||!b)return NULL;
    int countA=1;
    int countB=1;
    while(a->next||b->next){
        if(a->next){
            countA++;
            a=a->next;
        }
        if(b->next){
            countB++;
            b=b->next;
        }
    }
        int start=countA<countB?countB-countA:countA-countB;
        int i=1;
        struct ListNode* cc;
        struct ListNode* dd;
        cc=countA>=countB?headA:headB;
        dd=countA<countB?headA:headB;
        while(cc&&dd){
            while(i<=start){
                cc=cc->next;
                i++;
            }
            if(cc==dd)return cc;
            if(cc==NULL||dd==NULL)return NULL;
            cc=cc->next;
            dd=dd->next;
        }
    return NULL;
}
