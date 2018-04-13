int turnOnTheLights(int n, int k){
    int l[100];
    int first=1;
    memset(l,0,sizeof(l));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j%i==0){
                l[j]=!l[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(l[i]){
            if(first){
                first=0;
                printf("%d", i);
            }
            else{
                printf(" %d",i);
            }
        }

    }

}
