bool canJump(int* nums, int numsSize) {//////////这方法打败了1.23%。。。太慢了
    if(numsSize==1)return true;
    int next=1;
    for(int i=0;i>=0;){
       next=i+nums[i];
        if(next>=numsSize-1)return true;
        if(nums[next]==0){
            nums[i]-=1;
            if(i!=0)i--;
        }
        else i=next;
        if(next==0)return false;
        if(nums[i]==0)i--;
     }
    return false;
}
//////////////////////////////////////////////////////人家的方法还是聪明啊
bool canJump(int* nums, int numsSize) {
    if(numsSize==1)return true;
    int maxjump=nums[0];
    for(int i=0;i<numsSize;i++){
        if(i+maxjump>=numsSize-1)return true;
        if(nums[i]>maxjump)maxjump=nums[i];
        if(maxjump==0)return false;
        maxjump--;
    }
    return false;
}
