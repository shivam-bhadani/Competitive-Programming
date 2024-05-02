/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 20;

int n;
vector<int> adj[N];
int cache[N][1 << N];

ll dp(int node, int mask) {
	if (mask == (1 << n) - 1) {
		return 1;
	}
	if (node == n - 1) {
		return 0;
	}
	if (cache[node][mask] != -1) {
		return cache[node][mask];
	}
	ll ans = 0;
	for (auto& it : adj[node]) {
		if (mask & (1 << it)) continue;
		ans += dp(it, mask | (1 << it));
		ans %= MOD;
	}
	return cache[node][mask] = ans;
}

int main() {
	IOS
	memset(cache, -1, sizeof cache);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
	}
	cout << dp(0, 1);
}