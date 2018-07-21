
int minDistance(char* word1, char* word2) {
    int len1=strlen(word1);
    int len2=strlen(word2);
    char** dis=malloc(sizeof(char*)*(len1+1));
    for(int i=0;i<len1+1;i++)dis[i]=malloc(len2+1);
    for(int i=0;i<len2+1;i++)dis[0][i]=i;
    for(int i=0;i<len1+1;i++)dis[i][0]=i;
    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){
            if(word1[i-1]==word2[j-1])dis[i][j]=dis[i-1][j-1];
            else{
                int m=dis[i-1][j-1]>dis[i-1][j]?dis[i-1][j]:dis[i-1][j-1];
                m=m>dis[i][j-1]?dis[i][j-1]:m;
                dis[i][j]=m+1;
            }
        }
    }
    return dis[len1][len2];
}
