/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int dp[1005][1005];
 
ll solve(int i, int j, vector<string>& a) {
    if(i==a.size()-1 && j==a.size()-1) {
        return 1;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int ans = 0;
    if(i+1<a.size() && a[i+1][j]=='.') {
        ans =  (ans + solve(i+1, j, a)) % MOD;
    }
    if(j+1<a.size() && a[i][j+1]=='.') {
        ans = (ans + solve(i, j+1, a)) % MOD;
    }
    return dp[i][j] = ans % MOD;
}

int main() {
    int n; 
    cin >> n; 
    vector<string> a(n); 
    for(auto& s: a) {
        cin >> s;
    }
    memset(dp, -1, sizeof dp);
    if(a[n-1][n-1]=='*' || a[0][0]=='*') {
        cout << "0";
    }
    else {
        cout << solve(0, 0, a);
    }
}