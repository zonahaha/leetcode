#define MIN -2147483648
#define MAX 2147483647
int myAtoi(char* str) {
    long long  res=0;
    bool first = true;//用来判断空格是不是在字符串首位
    int sign=1;
    long long temp=0;
    if(*str==NULL)
        return 0;
    while(*str!=NULL){
        while(isdigit(*str)){//单纯数字的情况
            first = false;
            temp=temp*10+*str-'0';
            *str++;
             if(temp*sign>MAX||temp*sign<MIN){
                 temp*=sign;
                res=temp>MAX?MAX:MIN;
                return res;
            }
        }
        temp=temp*sign;
        res+=temp;
        if(res>MAX||res<MIN){//结果溢出则输出最大值或最小值
        res=res>MAX?MAX:MIN;
        return res;
    }
        sign=1;
        temp=0; 
        while(isalpha(*str)){
            first = false;
            return res;
        }
        while(*str=='+'||*str=='-'){//遇到加减符号
            first = false;
            if(*(str+1)=='+'||*(str-1)=='+'||*(str+1)=='-'||*(str-1)=='-'){//遇到两个加减符号相邻时，判断为不合法，直接结束
                return 0;
            }
            sign = (*str=='+')?1:-1;
            *str++;
            continue;
        }
        if(*str==' '){
            if(first==false)//空格在数字以后出现，不合法，直接返回已有结果
            return res;
            else{//空格位于字符串首位，直接跳过
                *str++;
                continue;
            }
        }
    }
    return res*sign;
}
