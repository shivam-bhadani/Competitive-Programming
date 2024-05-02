/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

// Kosaraju's Algorithm

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> radj[N];
vector<int> scc_adj[N];
vector<int> vis(N), col(N);
vector<ll> dp(N), compVal(N), k(N);
stack<int> st;

void clear_vis() {
	for (int i = 1; i < N; i++) {
		vis[i] = 0;
	}
}

void dfs1(int node) {
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (vis[it] == 0) {
			dfs1(it);
		}
	}
	st.push(node);
}

void dfs2(int node, int c) {
	vis[node] = 1;
	col[node] = c;
	compVal[c] += k[node];
	for (auto& it : radj[node]) {
		if (vis[it] == 0) {
			dfs2(it, c);
		}
	}
}

void dfs3(int node) {
	vis[node] = 1;
	dp[node] = compVal[node];
	for (auto& it : scc_adj[node]) {
		if (vis[it] == 0) {
			dfs3(it);
		}
		dp[node] = max(dp[node], compVal[node] + dp[it]);
	}
}

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs1(i);
		}
	}
	clear_vis();
	int cnt = 0;
	while (!st.empty()) {
		int node = st.top();
		st.pop();
		if (vis[node] == 0) {
			++cnt;
			dfs2(node, cnt);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto& it : adj[i]) {
			int u = col[i], v = col[it];
			if (u != v) {
				scc_adj[u].push_back(v);
			}
		}
	}
	clear_vis();
	for (int i = 1; i <= cnt; i++) {
		if (vis[i] == 0) {
			dfs3(i);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= cnt; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}