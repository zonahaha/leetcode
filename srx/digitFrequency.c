#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num[10]={0};
    char ch;
    while(scanf("%c",&ch)==1){
        if(isdigit(ch))num[ch-'0']++;
    }
    for(int i=0;i<9;i++)printf("%d ",num[i]);
    printf("%d",num[9]);
    return 0;
}
