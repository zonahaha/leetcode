uint32_t reverseBits(uint32_t n) {//参数其实就是一个二进制数了，我把它当成十进制在算，所以很慢
    int i=31;
    int j=0;
    uint32_t res=0;
    while(i>=0){
        if(n>=pow(2,i)){
            res+=pow(2,31-i);
            n-=pow(2,i);
        }
        i--;
    }
    return res;
}
///////////////////////////////////////////别人的：这里要熟悉左移右移的操作
uint32_t reverseBits(uint32_t n) {
    int res=0;
    int mask=1;
   for(int i=0;i<32;i++){
       res=res<<1;
       if(n&mask==1)res+=1;
       n=n>>1;
   }
    return res;
}
