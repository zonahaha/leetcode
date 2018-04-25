char *addBinary(char *a, char *b) {
    char *res=NULL;
    if (a == NULL || b == NULL) {
        res = a == NULL ? b : a;
        return res;
    }
    int len1 = strlen(a) - 1;
    int len2 = strlen(b) - 1;
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    res = malloc(sizeof(char) * (len+3));//重点！！！！！多申请一点！！！然后手动赋值'\0'使字符串终止，否则提交的时候就会莫名其妙多出来一个乱码！！
    memset(res, '0', len+3);
    int j = len;
    int add = 0;
    while (j>=0) {
        if (len1 < 0 && len2 >= 0)add = (b[len2] - '0') + (res[j] - '0');
        else if (len2 < 0 && len1 >= 0)add = (a[len1] - '0') + (res[j] - '0');
        else if(len1<0 && len2 < 0)add=res[j]-'0';
        else add = (a[len1] - '0') + (b[len2] - '0') + (res[j] - '0');
        if (add == 1) {
            res[j--] = '1';
        } else if (add == 0) {
            res[j--] = '0';
        } else if (add == 2) {
            res[j] = '0';        
            res[j - 1] = '1';
            j--;
        } else if(add==3){
            res[j] = '1';   
            res[--j] = '1';
        } 
        len1--;
        len2--;
    }
    res[len+1]='\0';
    if(res[0]=='1')return res;
    else  return res+1;   
}
