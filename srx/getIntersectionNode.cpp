class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headA_copy = headA;
        ListNode* headB_copy = headB;
        while (headA_copy != headB_copy)
        {
            headA_copy = headA_copy ? headA_copy->next : headB;
            headB_copy = headB_copy ? headB_copy->next : headA;
        }
        return headA_copy;
    }
};
