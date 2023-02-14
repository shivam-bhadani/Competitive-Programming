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
    vector<int> a(n);
    for(auto& x: a) {
        cin >> x;
    }
    vector<int> dp(n+1, INT_MAX);
    dp[0] = INT_MIN;
    for(int i=0; i<n; i++) {
        int idx = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if(a[i]>dp[idx-1] && a[i]<dp[idx]) {
            dp[idx] = a[i];
        }
    }
    for(int i=n; i>=0; i--) {
        if(dp[i]!=INT_MAX) {
            cout << i;
            return 0;
        }
    }
}