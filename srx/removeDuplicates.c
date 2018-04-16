int removeDuplicates(int* nums, int numsSize) {
    int count=0;
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        printf("%d", nums[0]);
    nums[count++]=nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){  //重点是这里，原来写的是nums[i]!=NULL&&nums[i]!=nums[i-1]，这样写会漏掉num[i]=0的情况，程序会当做null,why？？？？         
            nums[count++]=nums[i];
        }
    }
    return count;
}
