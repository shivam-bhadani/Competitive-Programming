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
    int n, s; 
    cin >> n >> s; 
    vector<int> val(n), wt(n); 
    for(auto& x: val) {
        cin >> x;
    }
    for(auto& x: wt) {
        cin >> x;
    }
    vector<vector<int>> dp(n+5, vector<int>(s+5));
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=s; j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=val[i-1]){
                dp[i][j] = max(dp[i][j], wt[i-1] + dp[i-1][j-val[i-1]]);
            }
        }
    }
    cout << dp[n][s];
}