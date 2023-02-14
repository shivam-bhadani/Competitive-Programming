/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define nline '\n'

const int INF = -1e18;

class SparseTable {
public:
	vector<vector<int>> table;
	vector<int> logValues;
	int mxLog, n;
	int ID = INF;

	SparseTable(int s) {
		n = s;
		table.resize(n + 5);
		logValues.resize(n + 5);
		mxLog = log2(n);
		logValues[1] = 0;
		for (int i = 2; i <= n; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
		for (int i = 0; i < n; i++) {
			table[i].assign(mxLog + 1, ID);
		}
	}

	void merge(int &curr, int &a, int &b) {
		curr = min(a, b);
	}

	void build(vector<int>& a) {
		for (int i = 0; i < n; i++) {
			table[i][0] = a[i];
		}
		for (int j = 1; j <= mxLog; j++) {
			for (int i = 0; (i + (1 << j)) <= n; i++) {
				merge(table[i][j], table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int query(int L, int R) {
		int j = logValues[R - L + 1];
		int ans = ID;
		merge(ans, table[L][j], table[R - (1 << j) + 1][j]);
		return ans;
	}
};

void run_case()
{
	int n;
	cin >> n;
	vector<int> a(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> prefSum(n + 5);
	for (int i = 1; i <= n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	vector<int> prefPrefSum(n + 5);
	for (int i = 1; i <= n; i++) {
		prefPrefSum[i] = prefPrefSum[i - 1] + prefSum[i];
	}
	SparseTable st(n + 5);
	st.build(prefSum);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int lo = i, hi = n;
		int till = i - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int mn = st.query(i, mid);
			int mn_sum = mn - prefSum[i - 1];
			if (mn_sum >= 0) {
				till = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		if (till >= i) {
			int len = till - i + 1;
			ans += prefPrefSum[till] - prefPrefSum[i - 1] - len * prefSum[i - 1];
		}
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