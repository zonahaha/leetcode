typedef struct {
    int top;
    int *element;
} MinStack;
#define MAX=999999
/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *obj=malloc(maxSize*sizeof(MinStack));
    obj->element=(int *)malloc(sizeof(int)*maxSize);
    
    obj->top=-1;
    printf("end create\n");
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->element[++(obj->top)]=x;
    printf("end push\n");
}

void minStackPop(MinStack* obj) {
    obj->top--;
    printf("end pop\n");
}

int minStackTop(MinStack* obj) {
   
    printf("end get top\n");
    return obj->element[obj->top];
}

int minStackGetMin(MinStack* obj) {
    int min = INT_MAX;
    for(int i=0;i<=obj->top;i++){
        min=min<obj->element[i]?min:obj->element[i];
    }
    printf("end get min\n");
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj->element);
    printf("end free\n");
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
