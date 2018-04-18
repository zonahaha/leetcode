int strStr(char* haystack, char* needle) {
    int len1=strlen(haystack);
    int len2=strlen(needle);
    int j=0;
    int k=0;
    int m=1;
    int n=0;
    bool first=true;
    if(*haystack=='\0'){
        if(*needle==NULL)return 0;
        if(*needle!=NULL)return -1;
    }
    if(*needle==NULL)return 0;
    if(len1<len2)return -1;
    for(int i=0;i<len1;i++){
        while(haystack[i]==needle[j]) {
            if (first){
                k = i;
                first = false;
            }

            if (haystack[k + len2 - m] == needle[len2 - j - 1]) {
                n++;
                if (n>len2/2)return k;
                i++;
                j++;
                m++;
            }
            else  break;
        }
        if(!first){
            if(strlen(haystack)-k<strlen(needle))return -1;
            i=k;
            n=0;
            m=1;
            first=true;
        }
        j=0;

    }
    return -1;
}
