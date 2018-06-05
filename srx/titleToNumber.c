int titleToNumber(char* s) {
    int i=0;
    int res=0;
    while(s[i])res=26*res+s[i++]-'0'-16;
    return res;
       
}
int titleToNumber(char* s) {
    int i=0;
    int res=0;
    while(s[i]){
        res=26*res+s[i++]-64;//两种方法的区别是如何把字符串转换成整型数字，一个是-64，一个是-'0'-16，字符0对应的是49
    }
    return res;
       
}
