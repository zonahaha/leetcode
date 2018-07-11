bool isIsomorphic(char* s, char* t) {   ///////////////太慢了6.56%
    if(!s||!t){
        return false;
    }
    int len=strlen(s);
    int* ch=malloc(sizeof(int)*(len+1));
    for(int i=0;i<len;i++){
        char ss=s[i];
        char tt=t[i];
        int k=i;
        if(ss!=tt){
            for(int i=k;i<len;i++){
                if(s[i]==ss&&ch[i]!=1){
                    if(t[i]==tt&&ch[i]!=1){
                        ch[i]=1;
                        s[i]=tt;
                    }
                    else return false;
                }
                else if(t[i]==tt&&s[i]!=ss&&ch[i]!=1)return false;
            }
        }
        else if(ch[i]!=1){
            for(int i=k;i<len;i++){
                if((s[i]==ss||t[i]==ss)&&s[i]!=t[i])return false;
            }
        }
    }

    return true;
}
