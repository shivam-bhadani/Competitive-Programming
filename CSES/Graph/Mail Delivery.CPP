/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

typedef long long ll;

// Euler Circuit
// Hierholzer's Algorithm

const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
int see[N], degree[N];
vector<int> ans;

void dfs(int node) {
	while (!adj[node].empty()) {
		auto it = adj[node].back();
		adj[node].pop_back();
		if (see[it.second]) continue;
		see[it.second] = 1;
		dfs(it.first);
	}
	ans.push_back(node);
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		++degree[u];
		++degree[v];
	}
	for (int i = 1; i <= n; i++) {
		if (degree[i] & 1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	dfs(1);
	if ((int)ans.size() != m + 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (auto& x : ans) {
		cout << x << " ";
	}
}