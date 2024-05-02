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

// Bellman–Ford Algorithm

const int N = 2505;
const ll INF = 1e18;

int n, m;
vector<int> adj[N];
int vis[N], reach[N];
ll dis[N];
vector<vector<int>> edges;

void clear_vis() {
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
	}
}

void dfs1(int node) {
	reach[node] = 1;
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (vis[it] == 0) {
			dfs1(it);
		}
	}
}

int dfs2(int node) {
	if (node == n) {
		return 0;
	}
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (vis[it] == 0) {
			if (!dfs2(it)) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		edges.push_back({u, v, -w});
	}
	for (int i = 0; i <= n; i++) {
		dis[i] = INF;
	}
	dis[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (auto& it : edges) {
			int u = it[0], v = it[1], w = it[2];
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
			}
		}
	}
	dfs1(1);
	for (auto& it : edges) {
		int u = it[0], v = it[1], w = it[2];
		if (dis[u] + w < dis[v]) {
			clear_vis();
			if (reach[u] && !dfs2(u)) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << -dis[n];
	return 0;
}