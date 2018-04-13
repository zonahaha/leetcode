int romanToInt(char* s) {
    int i=0;
    int result=0;
    while(s[i]) {
        i += 1;
        char m = s[i - 1];
        switch (m) {
            case 'M':
                result += 1000;
                continue;
            case 'D':
                result += 500;
                continue;
            case 'C':
                if (s[i] == 'M') {
                    result += 900;
                    i += 1;
                    continue;
                }
                else if(s[i]=='D'){
                    result += 400;
                    i+=1;
                    continue;
                }
                else {
                    result += 100;
                    continue;
                }
            case 'L':
                result += 50;
                continue;
            case 'X':
                if (s[i] == 'L') {
                    result += 40;
                    i += 1;
                    continue;
                }
                else if (s[i] == 'C') {
                    result += 90;
                    i += 1;
                    continue;
                }
                else {
                    result += 10;
                    continue;
                }
            case 'V':
                result += 5;
                continue;
            case 'I':
                if (s[i] == 'X') {
                    result += 9;
                    i+=1;
                    break;
                } else if (s[i] == 'V') {
                    result += 4;
                    i+=1;
                    break;
                }
                else {
                    result += 1;
                    continue;
                }
        }
    }
    return result;
}
