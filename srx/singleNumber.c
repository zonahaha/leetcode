////////////////////////////////////////////用的快速排序，先排序，然后再找不相等的数
void swap(int* a,int* b){/////////////////////////swap函数和我想象的不一样啊，这里要注意参数是指针还是只是复制了实参的值进行计算
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int* nums, int low,int high){
    int pivot;
    if(low<high){
        pivot=partition(nums,low,high);
        sort(nums,low,pivot-1);
        sort(nums,pivot+1,high);
    }
}
int partition(int* nums,int low, int high){
    int pivotkey;
    pivotkey=nums[low];
    while(low<high){
        while(low<high&&nums[high]>=pivotkey)
            high--;
        swap(&nums[low],&nums[high]);
        while(low<high&&nums[low]<=pivotkey)
            low++;
        swap(&nums[low],&nums[high]);
    }
    return low;
}
int singleNumber(int* nums, int numsSize) {
       sort(nums,0,numsSize-1);
       for(int i=0;i<numsSize-1;i+=2){
      
        if(nums[i]!=nums[i+1])return nums[i];
    }
    return nums[numsSize-1];
}
/////////////////////////////////////////////第二种，非常简单的方法，用按位异或后赋值操作，a^a=0,a^0=a原理，最后只剩下落单的那个数，牛逼啊这种解法
int singleNumber(int* nums,int numsSize){
    int res;
    for(int i=0;i<numsSize;i++){
        res^=nums[i];
    }
    return res;
}
