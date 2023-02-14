/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int dp[505][505];

int solve(int a, int b) {
    if(a>b) swap(a, b);
    if(a==b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    int ans = INT_MAX;
    for(int i=1; b-i>=1; i++) {
        ans = min(ans, 1 + solve(a, i) + solve(a, b-i));
    }
    for(int i=1; a-i>=1; i++) {
        ans = min(ans, 1 + solve(i, b) + solve(a-i, b));
    }
    return dp[a][b] = ans;
}

int main() {
    int a, b; cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << solve(a, b);
}