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
    ll n; cin >> n;
    ll sum = n * (n + 1);
    if(sum % 4) {
        cout << "0";
        return 0;
    }
    sum /= 4;
    vector<vector<ll>> dp(n+5, vector<ll>(sum+5));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-i>=0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    ll mod_inverse_of_two = 500000004;
    ll ans = (dp[n][sum] * mod_inverse_of_two) % MOD;
    cout << ans;
}