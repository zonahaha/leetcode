char* convertToTitle(int n) {
    char* s=(char*)malloc(sizeof(char)*1000);
    int i=0;
    int j=0;
    while(n){ 
        if(n%26!=0)s[i++]=n%26+16+'0';
        else {  //'0'->48
            s[i++]=n%26+42+'0';//还有这里，早点看清楚0对应的ACSII值啊蠢货
            n-=26;//这里真的是折磨了我一辈子，数学学得东西呢？？？
        }
        n=n/26;
    }
    char* res=(char*)malloc(sizeof(char)*(i+1));
    while(s[j]){
        res[j++]=s[--i];
    }
    return res;
}
