bool isPalindrome(int x) {
    int first = 1;
    if(x>10){
        int y[10];
        int i=0;
        memset(y,0,sizeof(y));
        while(x/10!=0){
            y[i++]=x%10;
            x=x/10;
        }
        y[i]=x;
        int j=0;

        while(j<=i){
            if(y[j++]==y[i--]){
                continue;
            }
            else{
                first=0;
                break;
            }
        }
    }
    else if(x<10&&x>=0){
        first=1;
    }
    else{
        first = 0;
    }
    return first;
}
