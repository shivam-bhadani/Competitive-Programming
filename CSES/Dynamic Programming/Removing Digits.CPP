/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<ll> dp(n+5, INT_MAX);
    dp[0] = 0;
    for(ll i=1; i<=n; i++) {
        for(auto& c: to_string(i)) {
            dp[i] = min(dp[i], dp[i-(c-'0')] + 1);
        }
    }
    cout << dp[n];
}