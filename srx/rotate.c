int getRound(int a,int b){
    return a==0?b:getRound(b%a,a);
}
void rotate(int* nums, int numsSize, int k) { 
    int count=0;
    int i=0;
    int temp=0;
    if(k>0&&numsSize>1){
    if(k>numsSize)k=k%numsSize;
    int round=getRound(k,numsSize);////////////次数很重要，可能会重复，但是避免遗漏
    while(count<round){
        i=count;
        temp=nums[i];
        do{  
            int newI=(i+k)%numsSize;//////////这句话很关键啊，要找到规律啊
            i=newI;
            int newtemp=nums[newI];
            nums[newI]=temp;
            temp=newtemp;             
        }while(i!=count);//////////////解决那种起点终点相同的置换
        count++;
        }
    }
}
