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

const int N = 1005;

int n, m, k;
vector<int> adj[N];
int cap[N][N];
int par[N];
vector<pair<int, int>> edges;

int bfs() {
	memset(par, -1, sizeof par);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto& it : adj[node]) {
			if (cap[node][it] && par[it] == -1) {
				par[it] = node;
				q.push(it);
			}
		}
	}
	return par[n + m + 1] != -1;
}

int main() {
	IOS
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		if (cap[u][v + n]) continue;
		adj[u].push_back(v + n);
		adj[v + n].push_back(u);
		cap[u][v + n] = 1;
		edges.push_back({u, v});
	}
	for (int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		cap[0][i] = 1;
	}
	for (int i = n + 1; i <= n + m; i++) {
		adj[i].push_back(n + m + 1);
		adj[n + m + 1].push_back(i);
		cap[i][n + m + 1] = 1;
	}
	int ans = 0;
	while (bfs()) {
		int node = n + m + 1;
		while (node != 0) {
			int p = par[node];
			cap[p][node] -= 1;
			cap[node][p] += 1;
			node = p;
		}
		ans += 1;
	}
	cout << ans << '\n';
	for (auto& x : edges) {
		if (!cap[x.first][x.second + n]) {
			cout << x.first <<  ' ' << x.second << '\n';
		}
	}
	return 0;
}