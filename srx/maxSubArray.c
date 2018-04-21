int maxSubArray(int* nums, int numsSize) {
    int res=0;
    int temp=0;
    for(int i=0;i<numsSize;i++){
        if(temp<0){
            temp=nums[i];
        }
        else{
            temp+=nums[i];
        }
        if(temp>res)res=temp;
    }
    return res;
}
