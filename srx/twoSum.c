/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 ////////////////////////////我的方法是先利用二分法找到一半大小的值的下标，然后分别将中值两边的数相加求和
int findhalf(int *numbers,int target,int start, int end){
    if(end-start==1)return start;
    int mid=(start+end)/2;
    if( numbers[mid]==target/2)return mid;
    else if( numbers[mid]<target/2)mid=findhalf(numbers,target,mid,end);
    else mid=findhalf(numbers,target,start,mid);
    return mid;
}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *res=malloc(sizeof(int)*2);
    *returnSize=2;
    if(target==0){
        res[0]=1;
        res[1]=2;
        return res;
    }
    int start=0;
    int end=numbersSize-1;
    int halfIndex=findhalf(numbers,target, start,end);
    int low=halfIndex;
    int high=halfIndex+1;
    while(true){
        int sum=numbers[low]+numbers[high];
        if(sum==target){
            res[0]=low+1;
            res[1]=high+1;
            break;
        }
        else if(sum<target)high++;
        else low--;
    }
    return res;
}
