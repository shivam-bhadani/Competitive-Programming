/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

struct Project {
    ll st, ed, money;
};

bool compare(Project a, Project b) {
    return a.ed < b.ed;
}


int main() {
    int n; cin >> n;
    vector<Project> a(n);
    for(auto& x: a) { 
        cin >> x.st >> x.ed >> x.money;
    }
    sort(a.begin(), a.end(), compare);
    vector<ll> endPoints(n);
    for(int i=0; i<n; i++) {
        endPoints[i] = a[i].ed;
    }
    vector<ll> dp(n+5);
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        int j = lower_bound(endPoints.begin(), endPoints.end(), a[i-1].st) - endPoints.begin();
        dp[i] = max(dp[i], a[i-1].money + dp[j]);
    }
    cout << dp[n];
}