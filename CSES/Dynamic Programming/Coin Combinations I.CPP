/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int main() {
    int n, s; 
    cin >> n >> s; 
    vector<int> a(n);
    for(auto& x: a) {
    	cin >> x;
    }
    vector<ll> dp(s+5);
    dp[0] = 1;
    for(ll i=1; i<=s; i++) {
        for(ll j=0; j<n; j++) {
            if(a[j]<=i) {
                dp[i] = (dp[i] + dp[i-a[j]]) % MOD;
            }
        }
    }
    cout << dp[s];
}