#define MAXSIZE 10000
char *countAndSay(int n) {
    int i = 2;
    int j=0;
    int k=0;
    int res[MAXSIZE];
    int next[MAXSIZE];
    char* ch;
    ch=(char*)malloc(10000*sizeof(char));
    int count = 1;
    memset(res,0,sizeof(res));
    memset(next,0,sizeof(next));
    if (n == 0)return NULL;
    if (n == 1)next[0]=res[0] = 1;
    if (n >= 2) {
        next[0]=res[0] = 1;
        next[1]=res[1] = 1;
    }
    while (i < n) {
        i++;
        while(res[k]!=0){
            while (res[k] == res[k + 1]) {
                count++;
                k++;
            }
            next[j++] = count;
            next[j++] = res[k];
            count = 1;
            k++;
        }
       if(i<n){
            int m=-1;
            while(next[++m])res[m]=next[m];
            j=0;
            k=0;
        }
    }
    i = 0;
    j=0;
    while (next[i]!=0) {
         ch[j++]=next[i++]+'0';
    }
    return ch;
}
