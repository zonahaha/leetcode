int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    if(triangle==NULL)return 0;
    for(int i=triangleRowSize-1;i>-1;i--){
        for(int j=0;j<triangleColSizes[i]-1;j++){
            triangle[i-1][j]+=triangle[i][j]<triangle[i][j+1]?triangle[i][j]:triangle[i][j+1];
        }
    }        
    return triangle[0][0];
}
