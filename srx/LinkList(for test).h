//
// Created by Administrator on 2018/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wingdi.h>
#include <time.h>

#ifndef INDEX_LINKLIST_H
#define INDEX_LINKLIST_H
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define IS_EMPTY(first) (!first)
typedef int ElemType;
typedef int Status;

#endif //INDEX_LINKLIST_H
typedef struct listNode *ListPointer;
struct listNode{
    ElemType val;
    struct listNode *next;
}listNode;

void init(ListPointer *L){
    *L=(ListPointer)malloc(sizeof(listNode));//产生一个头结点,并使L指向次头结点
    if(!(*L)){
        printf("存储分配失败");
        (*L)->next = NULL;//指针域为空
    }
}
void createList(ListPointer *L, int n){//头插法
     ListPointer p;
     srand(time(0));
     *L=(ListPointer)malloc(sizeof(listNode));
    (*L)->next=NULL;//建立一个带头结点的单链表
    for(int i=0;i<n;i++){
        p=(ListPointer)malloc(sizeof(listNode));
        p->val=rand()%100+1;
        p->next=(*L)->next;//插到表头
        (*L)->next=p;//p就是一直是表头节点
    }
}
void createListTail(ListPointer *L, int n){//尾插法
    ListPointer p,r;
    srand(time(0));
    *L=(ListPointer)malloc(sizeof(listNode));
    r=*L;//r是指向尾部的结点
    for(int i=0;i<n;i++){
        p=(ListPointer)malloc(sizeof(listNode));
        p->val=rand()%100+1;
        p=r->next;
        r=p;
    }
    r->next=NULL;
}
void insert(ListPointer *first, ListPointer x){
    ListPointer temp;
    temp = (ListPointer *)malloc(sizeof(ListPointer));
    scanf("%d",&temp->val);
    if(*first){
        temp->next=x->next;
        x->next=temp;
    }
    else{
        temp->next=NULL;
        *first=temp;
    }
}
void delete(ListPointer *first, ListPointer  trail, ListPointer x){
        if(trail){
            trail->next=x->next;
        }
        else{
            *first=(*first)->next;
        }
}
void print(ListPointer first){
    ListPointer p=first->next;
    while(p){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
Status isEmpty(ListPointer L){
    if(L->next){
        return FALSE;
    }
    return TRUE;
}
Status clearList(ListPointer *L){
    ListPointer p,q;
    p=(*L)->next;//指向第一个节点，p的格式总是和L保持一致
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}
int ListLength(ListPointer L){
    int len=0;
    ListPointer p;
    p=L->next;
    while(p){
        p=p->next;
        len++;
    }
    return len;
}
Status getElem(ListPointer L,int i,ElemType *e){
    ListPointer p;
    p=L->next;//p指向链表的第一个结点
    int j=1;
    while(p&&j<i){
        j++;
        p=p->next;
    }
    if(!p||j>i){
        printf("elemment does not exist");
        return ERROR;
    }
    *e=p->val;
    return OK;
}
int locateElem(ListPointer L,ElemType e){
    ListPointer p;
    p=L->next;
    int i=0;
    while(p){
        i++;
        if(p->val==e){
            return i;
        }
        p=p->next;
    }
    return 0;
}
Status ListInsert(ListPointer *L,int i, ElemType e){
    ListPointer p;
    p=*L;//这里的p应该是指向头节点，无数值域的，这样插入的时候就刚好和j保持一致，p指向第i-1个节点，在后面插入新节点
    int j=1;
    while(p&&j<i){
        j++;
        p=p->next;
    }
    if(!p||j>i){
        return ERROR;
    }
    ListPointer x;
    x=(ListPointer)malloc(sizeof(listNode));
    x->next=p->next;//此时p指向第i-1个结点
    x->val=e;
    p->next=x;
    return OK;
}
Status ListDelete(ListPointer *L,int i, ElemType *e){
    ListPointer p,q;
    p=*L;
    int j=1;
    while(p->next&&j<i){//这里因为p最后找到的是第i-1个结点，必须保证第i个结点存在，因此while里面条件是p->next
        j++;
        p=p->next;
    }
    if(!p->next||j>i){
        return ERROR;
    }
    q=p->next;//此时p指向第i-1个结点
    *e=q->val;
    p->next=q->next;
    free(q);
    return OK;
}
/////////////////////////////////////////////////////////测试，目前还是很不熟练，形参里面到底是带星号
////////////////////////////////////////////////////////////还是不带星号，取决于链表是否改变，改变则用指针的地址，不改变则直接传指针
///////////////////////////////////////////////////////////////里面的指针也要保持一致等等，再多看几遍吧
int main() {
  ListPointer L;
  init(&L);
  createList(&L,20);
  print(L);
    return 0;
}
