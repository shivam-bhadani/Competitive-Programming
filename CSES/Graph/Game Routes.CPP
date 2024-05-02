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

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
vector<int> radj[N];
vector<int> topo;
int vis[N];
int dp[N];

// Kahn's algorithm
bool topoSort() {
	topo.clear();
	vector<int> indeg(n + 5);
	for (int i = 1; i <= n; i++) {
		for (auto& it : adj[i]) {
			++indeg[it];
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}
	int no_of_node = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		++no_of_node;
		for (auto& it : adj[node]) {
			--indeg[it];
			if (indeg[it] == 0) q.push(it);
		}
	}
	return no_of_node == n;
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	topoSort();
	dp[1] = 1;
	for (auto& u : topo) {
		for (auto& v : radj[u]) {
			dp[u] = (dp[u] + dp[v]) % MOD;
		}
	}
	cout << dp[n];
	return 0;
}