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

// Minimum Spanning Tree

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
int vis[N];
ll totalMSTWeight = 0;

bool prims() {
	totalMSTWeight = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; // {wt, node, par}
	pq.push({0, 1, -1});
	while (!pq.empty()) {
		ll wt = pq.top()[0];
		int node = pq.top()[1];
		int parent = pq.top()[2];
		pq.pop();
		if (vis[node]) continue;
		vis[node] = 1;
		totalMSTWeight += wt;
		for (auto& it : adj[node]) {
			if (!vis[it.first]) {
				pq.push({it.second, it.first, node});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			return 0;
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
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	if (!prims()) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << totalMSTWeight;
	return 0;
}