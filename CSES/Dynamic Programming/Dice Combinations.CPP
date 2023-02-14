/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
ll dp[1000005];
 
ll solve(ll s) {
    if(s==0) {
        return 1;
    }
    if(dp[s]!=-1) {
        return dp[s];
    }
    ll ans = 0;
    for(ll i=1; i<=min(6LL, s); i++) {
        ans = (ans + solve(s-i)) % MOD;
    }
    return dp[s] = ans;
}


int main() {
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    cout << solve(n);
}