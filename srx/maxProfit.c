int maxProfit(int* prices, int pricesSize) {
    int pro=0;
    int temp=0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<=prices[i+1]){
            for(int j=i+1;j<pricesSize;j++){
                if(i!=j&&prices[j]>prices[i]){
                    temp=prices[j]-prices[i];
                    if(pro<temp)pro=temp;
                }
            }  
        }
        
    }
    return pro;
}
/////////////////////////////////////////////////第二种方法，学习的100%解法
int maxProfit(int* prices, int pricesSize) {
    int min=prices[0];
    int temp=0;
   for(int i=1;i<pricesSize;i++){
       int minus=prices[i]-min;
       if(minus>temp)temp=minus;
       if(prices[i]<min)min=prices[i];
   }
    return temp;
}
