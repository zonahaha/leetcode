int mySqrt(int x) {
    long long y = x;
    if (y <= 1)return y;
    int d;
    d = y % 2 == 0 ? y / 2 : (y + 1) / 2;
    int left = 0;
    int right = y;
    long long mid = d;
    while (d != 1) {
        if (mid * mid > y) right -= d;
        else if (mid * mid < y)left += d;
        else if (y / mid == mid) return mid;
        d = (d + 1) / 2;
        mid = left + d;
    }
    if (mid * mid == y)return mid;
    else if (mid * mid < y) {
        if ((mid + 1) * (mid + 1) > y)return mid;
        return mid + 1;
    } else return mid - 1;
}
