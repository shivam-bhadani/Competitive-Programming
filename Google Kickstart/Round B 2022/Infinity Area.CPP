#include<bits/stdc++.h>
using namespace std;

#define ps(x,y) fixed<<setprecision(y)<<x

typedef long long ll;

const int MOD = 1000000007;
const double pi = 3.141592653;

void run_case();

int main() {
	ll test_cases; 
    cin >> test_cases;
    for(ll test_id=1; test_id<=test_cases; test_id++) {
        cout << "Case #" << test_id << ": ";
        run_case();
    }
}

void run_case() {
	ll r, a, b; 
	cin >> r >> a >> b;
	double ans = 0.0;
	while(r) {
		ans += (pi * r*r);
		r *= a;
		ans += (pi * r*r);
		r /= b;
	}
	cout << ps(ans, 6) << '\n';
}