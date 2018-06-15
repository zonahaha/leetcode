
int majorityElement(int* nums, int numsSize) {/////////////采用的是摩尔投票计数法，不同则减一，想同则加一
/////////////////////////////////////////////////count为0时更换新的元素，count能为0则说明该元素不是最多的元素
    int majority=0;
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            majority=nums[i];
            count++;
            continue;
        }
        if(nums[i]!=majority){
            count--;
        }
        else {
            count++;
        }
        if(count>numsSize/2)return majority;   
    }
    return majority;
}
///////////////////////////////////////////////////////第一种用的方法是先快速排序，然后再计数,这种方法，先排序再计数，时间很长
void swap(int* nums,int a,int b){
    int temp;
    temp=nums[a];
    nums[a]=nums[b];
    nums[b]=temp;
}
void Qsort(int* nums,int start, int end){
    int mid;
    if(start<end){
        mid=partion(nums,start, end);
        Qsort(nums,start,mid-1);
        Qsort(nums,mid+1,end);
    }
}
int partion(int* nums,int start, int end){
    while(start<end){
        int m=nums[start];
        while(start<end&&m<=nums[end])end--;
        swap(nums,start,end);
        while(start<end&&m>=nums[start])start++;
        swap(nums,start,end);
    }
    return start;
}
int majorityElement(int* nums, int numsSize) {
    Qsort(nums,0,numsSize-1);
    int count=0;
    int max=0;
    int num;
    for(int i=0;i<numsSize;i++){
       // printf("%d ",nums[i]);        
        if(nums[i+1]==nums[i])count++;
        else {
            if(count<max)count=0;
            else{
                max=count;
                num=nums[i];
                count=0;
                if(count>numsSize/2||max>numsSize/2)break;
            }
        }
        
    }
    return num;  
}
//////////////////////////////////////////////////
