// Problem Link - https://www.interviewbit.com/problems/divide-integers/

int Solution::divide(int p, int q) {
    long long a = p;
    long long b = q;
    if (b == 0) return INT_MAX;
    if (a == 0) return 0;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    int sign = 0;
    if ((p < 0 && q > 0) || (p > 0 && q < 0)) sign = 1;
    long long ans = 0, x = 0;
    for (int i = 31; i >= 0; i--) {
        if ((x + (b << i)) <= a) {
            x += (b << i);
            ans += (1LL << i);
        }
    }
    if (sign) ans = -ans;
    if (ans > INT_MAX || ans < INT_MIN) return INT_MAX;
    return ans;
}
