int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize<1)return 0;
    int res=0;
    for(int i =0;i<numsSize;i++){
        if(nums[i]<target){
            if(i==numsSize-1)res=numsSize;
            continue;
        }
        else if(nums[i]==target||nums[i]>target){
             res=i; 
            break;
        }  
    }
    return res;
}
