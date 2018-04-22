int lengthOfLastWord(char* s) {//第一种解法，倒序计数，这样是最快的
    int count=0;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]!=' '){
          count++;
          if(s[i-1]==' ')break;
        }
    }
    return count;
}
////////////////////////////////////////////////////////////////////
int lengthOfLastWord(char* s) {//第二种解法，正序计数，太慢了，提交以后都找不到我自己的用时排名好吗，用点脑子啊
    int count=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]!=' '){
          count++;
        }
        else if(s[i+1]!=' '&&i+1<strlen(s))count=0;
    }
    return count;
}
