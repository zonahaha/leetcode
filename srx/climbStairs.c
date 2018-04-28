int climbStairs(int n) {//递归的方式，但是会出现超时的问题，所以使用第二种方法
    int res=0;
    if(n<=2)return n;
    else{
        res=climbStairs(n-2)+climbStairs(n-1);
    }
    return res;
}

int climbStairs2(int n) {//用循环的方法可以通过
    if(n<=2)return n;
    int i=2;
    int res=0;
    int a[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    while (i<n){
        i++;
        a[i]=a[i-1]+a[i-2];//从a[3]开始计算
    }
    return a[n];
}
