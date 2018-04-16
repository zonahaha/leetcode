#define STACK_INITIAL_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
typedef int SElemType;//方便修改数据类型
typedef int Status;//同上，方便返回类型
typedef struct {
    SElemType *top;
    SElemType  *bottom;
    int stackSize;
}SqStack;//顺序栈
Status initStack(SqStack *S){
    S->bottom = (SElemType *)malloc(STACK_INITIAL_SIZE*sizeof(SElemType));
    if(!S->bottom)return ERROR;
    S->top=S->bottom;
    S->stackSize=STACK_INITIAL_SIZE;
    return OK;
}
Status Push(SqStack *S, SElemType e){
    if(S->bottom-S->top>=S->stackSize){
        S->bottom = (SElemType *)realloc(S->bottom,(S->stackSize+STACKINCREMENT)*sizeof(SElemType));
        if(!S->bottom){
            exit(OVERFLOW);
        }
        S->top=S->bottom+S->stackSize;
        S->stackSize+=STACKINCREMENT;
    }
    *S->top=e;
    S->top++;
    return OK;
}
//pop() 方法可以访问栈顶的元素， 调用后， 栈顶元素从栈中被永久性地删除。peek() 方法则只返回栈顶元素， 而不删除它。
Status Pop(SqStack *S){
    SElemType e;
    if(S->bottom==S->top){
        return ERROR;
    }
    --S->top;
    e = *S->top;
    return e;
}
Status getTop(SqStack *S){
    SElemType e;
    if(S->top==S->bottom){
        return ERROR;
    }
    e=*(S->top-1);//据说是因为定义的栈顶指针指向的是栈顶元素的下一位置，所以要-1
    return e;
}
Status empty(SqStack *S){
    if(S->bottom==S->top){
        return OK;
    }
    else{
        return 0;
    }

}
int main() {
    printf("Hello, World!\n");
    SqStack S;
    initStack(&S);
    for(int i=1;i<=3;i++){
        Push(&S,i);
    }
    for(int i=0;i<=3;i++){
        printf("%d",getTop(&S));
        Pop(&S);
    }
    return 0;
}
