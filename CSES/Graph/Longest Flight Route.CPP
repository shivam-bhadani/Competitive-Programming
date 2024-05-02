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

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
int vis[N];
vector<int> topo;

void dfs(int node) {
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (!vis[it]) {
			dfs(it);
		}
	}
	topo.push_back(node);
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	dfs(1);
	if (!vis[n]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	reverse(all(topo));
	vector<int> dis(n + 5), par(n + 5);
	for (auto& u : topo) {
		for (auto& v : adj[u]) {
			if (dis[v] < dis[u] + 1) {
				dis[v] = dis[u] + 1;
				par[v] = u;
			}
		}
	}
	vector<int> ans;
	int node = n;
	while (node != 1) {
		ans.push_back(node);
		node = par[node];
	}
	ans.push_back(1);
	reverse(all(ans));
	cout << (int)ans.size() << '\n';
	for (auto& x : ans) {
		cout << x << ' ';
	}
	return 0;
}