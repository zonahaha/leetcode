bool isHappy(int n) {
    int* nums=malloc(sizeof(int)*20);
    int i=0;
    int sum=0;
    int count=30;
    while(count--){/////////////这个30次我是看的别人的方法，，因为我想通过
    ////////////////////////////全局变量定义一个记录sum的数组，用来对比sum是否重复。但是总是报错，所以用了他的
        i=sum=0;
        while(n){
            nums[i++]=n%10;
            n/=10;
        }       
        i-=1;
        while(i>-1){  
            sum=sum+(nums[i]*nums[i]);
            i--;
        }
        if(sum==1)return true;
        n=sum;
    }
    return false;
}
