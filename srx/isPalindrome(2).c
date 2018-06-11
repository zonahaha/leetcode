bool isAlphaOrDigit(char c){
    if(!isalpha(c)&&!isdigit(c))return false;
    return true;
}
bool isPalindrome(char* s) {
    //printf("size=%d,%d",sizeof(s),strlen(s));
    int end=strlen(s)-1;
    int start=0;
   // printf("first start= %d end=%d",start, end);
    if(start==end)return true;
    while(start<=end){
        while(!isAlphaOrDigit(s[start]))start++;
        while(!isAlphaOrDigit(s[end])&&end>=0)end--;
        if(end<0)return true;
      //  printf("start=%d, %c,end=%d, %c\n",start,s[start],end, s[end]);
        if(isalpha(s[start])&&isalpha(s[end])&&toupper(s[start])!=toupper(s[end])){
         //   printf("unequal alpha %c %c\n",s[start],s[end]);
            return false;
        }
        else if((isdigit(s[start])||isdigit(s[end]))&&s[start]!=s[end]){
      //      printf("unequal digit %c %c\n",s[start],s[end]);
            return false;
        }
        start++;
        end--;
    }
    return true;
}
///////////////////////////////isalnum更快
