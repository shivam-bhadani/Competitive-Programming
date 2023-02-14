/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) {
        cin >> x;
    }
    vector<int> dp(N+5);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=N; j-a[i]>=0; j--) {
            if(dp[j-a[i]]) 
                dp[j] = 1;
        }
    }
    vector<int> ans;
    for(int i=1; i<=N; i++) {
        if(dp[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto& x: ans) {
        cout << x << ' ';
    }
}