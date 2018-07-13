void swap(int* nums,int low, int high){
    int temp;
    temp=nums[low];
    nums[low]=nums[high];
    nums[high]=temp;
}
void Qsort(int* nums,int low,int high){
    int pivote;
    while(low<high){
        pivote=partion(nums,low,high);
        Qsort(nums,low,pivote-1);
        low=pivote+1;/////////////这样做可以通过迭代而不是递归的方式减少堆栈深度，提高整体性能
    }
    
}
int partion(int* nums,int low, int high){
    int m=low+(high-low)/2;
    if(nums[low]>nums[high])swap(nums,low,high);
    if(nums[m]>nums[high])swap(nums,m,high);
    if(nums[m]<nums[low])swap(nums,low,high);///////////////这样做可以是low保持在中间，尽量减少交换次数
    int pivote=nums[low];
    while(low<high){
        //printf("zheli");
        while(low<high&&pivote<=nums[high])
            high--;
        swap(nums,low,high);//////这里要交换两次
        while(low<high&&pivote>=nums[low])
            low++;
        swap(nums,low,high);////////交换两次
    }
   // printf("%d",low);
    return low;
}
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize<=1)return false;
    Qsort(nums,0,numsSize-1);/////////////////////这次对快速排序进行 了部分优化，但是优化前后时间是一样的，，49.5%
    int fanwei=nums[0]+numsSize-1;
    if(nums[numsSize-1]<fanwei){
        printf("%d,first",nums[numsSize-1]);
        return true;
    }
    for(int i=0;i<numsSize-1;i++){
        printf("nums[%d]=%d ",i,nums[i]);
        if(nums[i]==nums[i+1])return true;
    }
    return false;
}
