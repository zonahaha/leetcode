#define MIN -2147483648
int maxSubArray(int* nums, int numsSize) {
    int res=MIN;
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
