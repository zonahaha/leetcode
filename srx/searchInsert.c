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
//////////////////////////////////////////////////////////第二种解法：二分法
int searchInsert2(int *nums, int numsSize, int target) {//二分法解决
    int i = 0;
    int res = 0;
    int h = 0;
    h = numsSize;
    if (target > nums[h - 1]) {
        return h;
    } else if (target == nums[h - 1]) {
        return h - 1;
    } else if (target <= nums[0]) {
        return 0;
    }
    i = (h + i) / 2;
    h = h / 2;
    while (nums[i] && h >= 1) {
        h = h / 2;
        if (nums[i] > target) {//左边
            i = i - h;
            continue;
        } else if (nums[i] == target) {
            res = i;
            return res;
        } else {//右边
            i = i + h;
        }
    }
    if (nums[i - 1] == target)return i - 1;
    else if (nums[i + 1] == target)return i + 1;
    else res = nums[i] > target ? i : i + 1;
    return res;
}
