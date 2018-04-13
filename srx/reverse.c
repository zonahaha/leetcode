int reverse(int x) {
    int y[10]={0};
    int j=0;
    if(x/10!=0){
        while(x/10){
            y[j++]=x%10;
            x=x/10;
        }
    }
    y[j]=x;
    long long result=0;
    int i=0;

        while(i<=j){
            if(i==0&&y[i]==0){
                i+=1;
                continue;
            }
            result=y[i++]+10*result;
        }
    if(result<2147483647&&result>-2147483648){
        printf("%d\n",result);
        return  result;
    }
    else{
        printf("0");
        return 0;
    }
}
