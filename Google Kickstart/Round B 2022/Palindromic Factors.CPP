#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

void run_case();

int main() {
    ll test_cases; 
    cin >> test_cases;
    for(ll test_id=1; test_id<=test_cases; test_id++) {
        cout << "Case #" << test_id << ": ";
        run_case();
    }
}

bool check(string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s==t;
}

void run_case() {
    ll n; cin >> n;
    ll ans = 0;
    ll till = sqrt(n);
    for(ll i=1; i<=till; i++) {
        if (n%i == 0) {
            if (n/i == i) {
                string s = to_string(i);
                if(check(s)) ans++;
            }
            else {
                string s = to_string(i);
                string t = to_string(n/i);
                if(check(s)) ans++;
                if(check(t)) ans++;
            }
        }
    }
    cout << ans << '\n';
}