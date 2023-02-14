// Problem Link - https://www.interviewbit.com/problems/count-total-set-bits/

typedef long long ll;
const int MOD = 1e9 + 7;
ll higestTwoPower(ll n) {
    ll x = 0;
    while ((1LL << x) <= n)
        x++;
    return x - 1;
}

ll func(ll n) {
    if (n <= 1) return n;
    ll x = higestTwoPower(n);
    // f(x) = 2^(x-1)*x + (n - 2^x + 1) + f(n-2^x);
    ll twoPowerX = (1 << x);
    ll twoPowerXminus1 = (1 << (x - 1));
    ll ans = (twoPowerXminus1 * x + (n - twoPowerX + 1) + func(n - twoPowerX)) % MOD;
    return ans;
}

int Solution::solve(int A) {
    return func(A);
}
