/**
 * Return an array of size *returnSize.返回的结果的大小是returnsize！要对应！
 * Note: The returned array must be malloced, assume caller calls free().要malloc！！
 */
////////////////////就是因为上面这两句话！！！就一直报错！！！
int *plusOne(int *digits, int digitsSize, int *returnSize) {   
    int k=0;
    int *res=(int*)malloc(sizeof(int)*digitsSize);//如果不分配，leetcode会报错提示空指针
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {//一般情况
            digits[i] += 1;
            break;
        } else if (digits[i - 1]&&i!=0) {//该位不是最高位为9的情况
            digits[i] = 0;
            if(digits[i-1]!=9){
                digits[i - 1] += 1;
                break;
            }
        } else {//最高位为9的情况
            k = 0;
            res=realloc(res,sizeof(int)*(digitsSize+1));//这个malloc指针到底怎么用的妈了个鸡
            res[k++] = 1;
            while (k <= digitsSize){
                res[k] = 0;
                k++;
            }
            *returnSize=digitsSize+1;
            return res;
        }
}
   *returnSize=digitsSize;//有时候结果一直为空，可能是题目中要求的变量一直没有赋值，比如这
                          //个returnSize，前面一直搞错了用法，return之前一定要确定这个值正确
   return digits;
   
}
