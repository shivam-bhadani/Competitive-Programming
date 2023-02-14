/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define nline '\n'

void run_case()
{
	int m, n, p;
	cin >> m >> n >> p;
	vector<vector<int>> a(m, vector<int>(n));
	for (auto& v : a) {
		for (auto& x : v) {
			cin >> x;
		}
	}
	p--;
	int ans = 0;
	for (int j = 0; j < n; j++) {
		int mx = 0;
		for (int i = 0; i < m; i++) {
			mx = max(mx, a[i][j]);
		}
		ans += mx - a[p][j];
	}
	cout << ans << nline;
}

int32_t main() {
	IOS
	int test_cases;
	cin >> test_cases;
	for (int test_id = 1; test_id <= test_cases; test_id++) {
		cout << "Case #" << test_id << ": ";
		run_case();
	}
	return 0;
}