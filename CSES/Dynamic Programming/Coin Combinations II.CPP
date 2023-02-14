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
    int n, target; 
    cin >> n >> target; 
    vector<ll> x(n); 
    for(auto& i: x) {
        cin >> i;
    }
    vector<vector<int>> dp(n+1, vector<int>(target+1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-x[i-1];
            if (left >= 0) {
                (dp[i][j] += dp[i][left]) %= MOD;
            }
        }
    }
    cout << dp[n][target] << endl;
}