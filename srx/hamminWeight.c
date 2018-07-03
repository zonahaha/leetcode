int hammingWeight(uint32_t n) {依然用的是十进制的方法，好蠢啊，但是时间并没有落后
    int count=0;
    while(n){
        if(n%2==1)count++;
        n/=2;
    }
    return count;
}
///////////////////////////////////////和1作与运算，不就知道末尾1位是不是1了吗撒币，二进制运算还得多练多熟悉
int hammingWeight(uint32_t n) {
    int count=0;
    while(n){
      if(n&1)count++;
        n=n>>1;
    }
    return count;
}
