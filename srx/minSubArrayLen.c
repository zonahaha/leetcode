int minSubArrayLen(int s, int* nums, int numsSize) {//非常慢的一种解法，蠢！
    int count=0;
    int min=INT_MAX;
    int sum=0;
    bool exit=false;
    for(int i=0;i<numsSize;i++){
        for(int j=i;j<numsSize&&count<=min;j++){
            sum+=nums[j];
            count++;
            if(sum>=s){
                exit=true;//exit a solution
                min=count<min?count:min;
                count=0;
                sum=0;
                break;
            }
            
        }
        sum=0;
        count=0;
    }
    return exit?min:0;
}
/////////////////////////////////////////////////////////////////别人的100%的solution
int minSubArrayLen(int s, int* nums, int numsSize) {
    int min=numsSize+1;//这里也是关键
    int sum=0;
    int left=0;
    int right=1;
    bool exit=false;
    sum=nums[0];
    while(right<numsSize){
        if(sum<s)
       sum+=nums[right++];
        else{
            exit=true;
            min=min<(right-left)?min:(right-left);
            sum-=nums[left++];
        }            
    }
    while(sum>=s){
        min=min<(right-left)?min:(right-left);
        sum-=nums[left++];
    }
    return min!=numsSize+1?min:0;
} 
