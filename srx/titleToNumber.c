int titleToNumber(char* s) {
    int i=0;
    int res=0;
    while(s[i])res=26*res+s[i++]-'0'-16;
    return res;
       
}
