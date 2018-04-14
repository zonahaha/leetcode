struct ListNode *mergeTwoLists(struct ListNode *l1,struct ListNode *l2){
    if(l1==NULL){
        return l2;
    }
    else if(l2==NULL){
        return l1;
    }
    if(l1->val<=l2->val){
        l1->next=mergeTwoLists(l1->next,l2);//这个递归的解法实在是太厉害了啊，人家还是厉害
        return l1;
    }
    else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
