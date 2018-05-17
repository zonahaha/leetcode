/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
     rowIndex+=1;
     if(rowIndex==0)return NULL;
     int** res=calloc(rowIndex,sizeof(int*));     
     int count=0;
     for(int i=0;i<rowIndex;i++){
         res[count++]=(int*)malloc(sizeof(int)*1000);
         for(int j=0;j<count;j++){
             if(j*i!=0&&j!=count-1)res[i][j]=res[i-1][j-1]+res[i-1][j];
             else res[i][j]=1;
         }
     }
    *returnSize=rowIndex;
     return res[rowIndex-1];    
}
