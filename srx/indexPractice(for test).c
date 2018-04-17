int Sum(int* begin,int* end){
    int n=end-begin;//得到的是begin到end之间元素的个数
    int res=0;
    for (int i=0;i<n;i++){
        res=res+begin[i];
    }
    return res;
}

int sum(int *begin, int *end){
    int res=0;
    for(;begin!=end;begin++){
        res=res+*begin;
    }
    return res;
}
int main(){
 int a[]={1,2,3}
 printf("%d %d",sum(a,a+3),Sum(a,a+4));
    return 0;
}
