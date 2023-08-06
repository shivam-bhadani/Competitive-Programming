/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 2e5 + 5;

vector<int> adj[N];
vector<ll> v(N), flatten(2 * N + 5), enter(N), leave(N);
int timer = 1;

void dfs(int node, int par) {
	flatten[timer] = v[node];
	enter[node] = timer++;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
	}
	flatten[timer] = v[node];
	leave[node] = timer++;
}

class SegTree {
public:
	vector<ll> segs;
	ll size = 0;
	ll ID = 0;

	SegTree(ll sz) {
		segs.assign(2 * sz, ID);
		size = sz;
	}

	ll comb(ll a, ll b) {
		return a + b;
	}

	void upd(ll idx, ll val) {
		segs[idx += size] = val;
		for (idx >>= 1; idx; idx >>= 1) segs[idx] = comb(segs[idx << 1], segs[idx << 1 | 1]);
	}

	ll query(ll l, ll r) {
		ll lans = ID, rans = ID;
		for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lans = comb(lans, segs[l++]);
			if (r & 1) rans = comb(segs[--r], rans);
		}
		return comb(lans, rans);
	}
};

int main() {
	IOS
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	SegTree st(2 * n + 5);
	for (int i = 1; i <= 2 * n; i++) {
		st.upd(i, flatten[i]);
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int s, x;
			cin >> s >> x;
			st.upd(enter[s], x);
			st.upd(leave[s], x);
		}
		else {
			int s;
			cin >> s;
			ll sum = st.query(enter[s], leave[s]);
			ll ans = sum / 2;
			cout << ans << '\n';
		}
	}
}