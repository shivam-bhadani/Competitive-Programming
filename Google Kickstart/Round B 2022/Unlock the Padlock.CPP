#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 405;
const int MOD = 1000000007;
const ll INF = 1e15;

void run_case();

int main() {
    ll test_cases; 
    cin >> test_cases;
    for(ll test_id=1; test_id<=test_cases; test_id++) {
        cout << "Case #" << test_id << ": ";
        run_case();
    }
}

ll dp[N][N][2];
ll n, d; 

ll solve(int i, int j, int f, vector<ll>& a) {
    if(i>=j) return 0;
    if(dp[i][j][f]!=-1) return dp[i][j][f];
    ll ans = INF;
    if(!f) {
        ll cost1 = solve(i+1, j, 0, a) + min(abs(a[i]-a[i+1]), d-abs(a[i]-a[i+1]));
        ll cost2 = solve(i+1, j, 1, a) + min(abs(a[i]-a[j]), d-abs(a[i]-a[j]));
        ans = min(cost1, cost2);
    }
    else {
        ll cost1 = solve(i, j-1, 0, a) + min(abs(a[j]-a[i]), d-abs(a[j]-a[i]));
        ll cost2 = solve(i, j-1, 1, a) + min(abs(a[j]-a[j-1]), d-abs(a[j]-a[j-1]));
        ans = min(cost1, cost2);
    }
    return dp[i][j][f] = ans;
}

void run_case() {
    cin >> n >> d;
    vector<ll> a(n);
    for(auto& x: a) {
        cin >> x;
    }
    memset(dp, -1, sizeof dp);
    ll ans1 = solve(0, n-1, 0, a) + min(a[0], abs(d-a[0])); // making all no.s equal to first
    ll ans2 = solve(0, n-1, 1, a) + min(a[n-1], abs(d-a[n-1])); // making all no.s equal to last
    ll ans = min(ans1, ans2);
    cout << ans << '\n';
}