int generate(int numRows, int columnSizes) {
    if(numRows==0)return NULL;
    int res=calloc(numRows,sizeof(int));
    columnSizes=calloc(numRows,sizeof(int));
    int count=0;
    for(int i=0;i<numRows;i++){
        res[count++]=(int)malloc(sizeof(int)1000);
        for(int j=0;j<count;j++){
            if(ji!=0&&j!=count-1)res[i][j]=res[i-1][j-1]+res[i-1][j];
            else res[i][j]=1;
        }
        (columnSizes)[count-1]=count;
    }
    return res;
}
