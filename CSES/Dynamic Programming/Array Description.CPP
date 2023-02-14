/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int dp[100005][105];
int m;
 
int solve(vector<int>& a, int n, int x) {
    if(x>m || x<1) return 0;
    if(n==1) {
        if(a[0]==x || a[0]==0) return 1;
        else return 0;
    }
    if(a[n-1]!=x && a[n-1]!=0) {
        return 0;
    }
    if(dp[n][x]!=-1) return dp[n][x];
    int ans = (solve(a, n-1, x-1) + 0LL + solve(a, n-1, x) + 0LL + solve(a, n-1, x+1)) % MOD;
    return dp[n][x] = ans;
}

int main() {
    int n; 
    cin >> n >> m; 
    vector<int> a(n); 
    for(auto& x: a) {
        cin >> x;
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(ll i=1; i<=m; i++) {
        ans = (ans + solve(a, n, i)) % MOD;
    }
    cout << ans;
}