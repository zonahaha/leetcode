bool isValid(char* s){
    int len = strlen(s);
    int i=0;
    char t;
    SqStack stack;
    initStack(&stack);//这句非常关键！！！一直exe报错来着！！！
    while(s[i]){
        i++;
        t=s[i-1];
        switch(t){
            case '{':
            case '(':
            case '[':
            Push(&stack,t);
            continue;
            case '}':
                if(getTop(&stack)!='{'){
                    return false;
                }
                Pop(&stack);
                continue;
            case ']':
                if(getTop(&stack)!='['){
                    return false;
                }
                Pop(&stack);
                continue;
            case ')':
                if(getTop(&stack)!='('){
                    return false;
                }
                Pop(&stack);
                continue;
        }

    }
    if(empty(&stack))//in case of "(("
        return true;
    else
        return false;
}
