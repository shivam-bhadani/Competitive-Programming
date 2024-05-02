/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 505;
const ll INF = 1e15;

vector<int> adj[N + 5];
vector<vector<ll>> capacity(N + 5, vector<ll>(N + 5));

int canReach(vector<int>& par, int src, int sink) {
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto& it : adj[node]) {
			if (capacity[node][it] && par[it] == -1) {
				par[it] = node;
				q.push(it);
			}
		}
	}
	return par[sink] != -1;
}

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v] += w;

	}
	vector<int> par(n + 5, -1);
	ll ans = 0;
	while (canReach(par, 1, n)) {
		ll mn = INF;
		int node = n;
		while (node != 1) {
			int p = par[node];
			mn = min(mn, capacity[p][node]);
			node = p;
		}
		node = n;
		while (node != 1) {
			int p = par[node];
			capacity[p][node] -= mn;
			capacity[node][p] += mn;
			node = p;
		}
		ans += mn;
		fill(par.begin(), par.end(), -1);
	}
	cout << ans << endl;
}
