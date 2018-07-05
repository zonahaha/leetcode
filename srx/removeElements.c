/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {////////////68.3%太慢了，而且代码太复杂了。。判断太多了
    struct ListNode* currentNode=head;
    struct ListNode* lastNode=head;
    struct ListNode* nextNode=NULL;
    if(currentNode==NULL)return head;
    if(currentNode->next)nextNode=currentNode->next;
    bool first=true;
    while(currentNode){
        if(val!=currentNode->val){
            printf("unequal\n");
            currentNode=currentNode->next;
            if(!first){
                lastNode=lastNode->next;
            }
            first=false;
            if(nextNode){
                if(nextNode->next)nextNode=nextNode->next;
            }
            //else nextNode=NULL;
        }
        else{
            if(nextNode){
                if(currentNode==head){//head
                    printf("head\n");
                    if(head->next)head=head->next;
                    currentNode=head;
                    lastNode=head;
                    if(nextNode&&currentNode->next)nextNode=currentNode->next;
                    else nextNode=NULL;
                }
                else{//regular
                    printf("regular\n");
                    lastNode->next=nextNode;
                    currentNode=nextNode;
                    if(nextNode->next)nextNode=nextNode->next;
                    else nextNode=NULL;
                }
            }
            else{//tail
                if(currentNode==head){//only one node
                    printf("one node\n");
                   head=NULL;
                    return head;
                }
                printf("tail\n");
                currentNode=NULL;
                nextNode=NULL;
                lastNode->next=NULL;
            }
        }
    }
    return head;
}
////////////////////////////////////////////////第二种
struct ListNode* removeElements(struct ListNode* head, int val){
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL)return NULL;
    while(head->val==val){//////////////这里直接处理删除头结点的情况
        if(head->next)head=head->next;
        else return NULL;
    }
    struct ListNode* p=head;
    while(p->next){
        if(val==p->next->val){
          p->next=p->next->next;      
        }
        else{
           p=p->next; 
        }
    }
    return head;
}
