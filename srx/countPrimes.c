int countPrimes(int n) {
    if(n<=2)return 0;

    int count=1;
    int* primes=(int*)malloc(sizeof(int)*n);
    if(n==3)return 1;
    for(int i=3;i<n;i+=2){///////////////这个i+=2和i++还是不一样的，完全省去了偶数的可能，时间是减少了一些
        if(primes[i]==0){
            count++;
            for(int j=3;j*i<n;j++){   
                primes[i*j]=1;
            }
        }
    }
   // free(primes);////////////不知道为啥加上这句提交的话就报错。。光运行结果的是对的
    return count;
}

/*
int countPrimes(int n) {
    int *hash=(int*)malloc(sizeof(int)*n);
    int count=0;
    for(int i=2;i<n;i++){
        if(hash[i]==0){
            count++;
            for(int j=2;j*i<n;j++){
                hash[i*j]=1;
            }
        }
    }
    return count;
}*/
