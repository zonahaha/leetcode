int jump(int* nums, int numsSize) {/////////////////嘿嘿嘿，还可以啊，虽然代码有点难看，但是100%
    if(numsSize<=1)return 0;
    int i=0;
    int count=1;
    int maxj=0;
    int max=0;
    int temp=0;
   while(i<numsSize-1){
        temp=i+nums[i];//最大距离
       if(temp>=numsSize-1)return count;
        max=i+nums[temp];//最大距离的最大距离
       if(max>=numsSize-1)return count+1;
        int compare=max;
        maxj=i+nums[i];
        for(int j=i;j<=temp;j++){
            int pro=j+nums[j];//走非最大距离的最大距离
            if(pro>max){
                maxj=j;
                max=pro;
            }
        }
        count++;
        i=maxj;
    } 
    return count;
}
