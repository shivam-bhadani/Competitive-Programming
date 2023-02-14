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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+5][m+5];
    for(ll i=0; i<=n; i++) {
        for(ll j=0; j<=m; j++) {
            if(i==0 || j==0) {
                dp[i][j] = max(i, j);
            }
            else {
                if(a[i-1]==b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                }
            }
        }
    }
    cout << dp[n][m];
}