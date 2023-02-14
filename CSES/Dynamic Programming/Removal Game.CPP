/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll dp[5005][5005];

ll solve(int i, int j, vector<ll>& a) {
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll move1 = a[i] + min(solve(i+2, j, a), solve(i+1, j-1, a));
    ll move2 = a[j] + min(solve(i+1, j-1, a), solve(i, j-2, a));
    return dp[i][j] = max(move1, move2);
}

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for(auto& x: a) {
        cin >> x;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, n-1, a);
}