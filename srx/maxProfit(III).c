int max(int a,int b){
    return a>b?a:b;
}
int maxProfit(int* prices, int pricesSize) {/////////////////////////一种非常慢的方法。。。
    int cur_pro=0;
    int max_pro=0;
    int res=0;
    int temp=0;
    for(int i=0;i<pricesSize-1;i++){
        for(int k=i+1;k<pricesSize;k++){
            if(prices[k]>prices[i]){
            temp=prices[k]-prices[i];
                int minus=prices[k]-prices[i];
            if(k<pricesSize-2){//左边中点固定时，找右边最大deprofit
                int min=prices[k+1];
                for(int j=k+1;j<pricesSize ;j++){
                    cur_pro=prices[j]-min;
                    min=-max(-prices[j],-min);
                    max_pro=max(cur_pro,max_pro);
                } 
             temp+=max_pro;//当前三点式最大profit
                max_pro=0;
            }
                 max_pro=0;
            temp=temp>minus?temp:minus;           
        }
        res=res>temp?res:temp;
          temp=0;   
        }
    }
    return res;
}
