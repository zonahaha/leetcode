int countOne(){
    char s[10];
    scanf("%s",s);///
    int tot=0;
    for(int i=0;i<=strlen(s);i++){
        if(s[i]=='1')tot++;///'1'
    }
    printf("%d\n",tot);
    return 0;
}
