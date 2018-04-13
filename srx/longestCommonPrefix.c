char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize<1){
        return "";
    }
    int len = strlen(strs[0]);
    int tempLen = 0;
    char* common = (char *)malloc(sizeof(char)*(len+1));
    strcpy(common,strs[0]);

    for(int i=1;i<strsSize;i++){
        tempLen=0;
        for(int j=0;j<strlen(common);j++){
            if(common[j]==strs[i][j]){
                tempLen++;
            }
            else{
                common[j]='\0';
                break;
            }
        }
        if(tempLen==0){
            return "";
        }
        if(tempLen<len){
            len=tempLen;
        }
    }

    return common;
}
