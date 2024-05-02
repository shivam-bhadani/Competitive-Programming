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

// Dijkstra’s Algorithm

const int N = 1e5 + 5;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> radj[N];
ll dis1[N], disn[N];
vector<vector<int>> edges;

void bfs1() {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});
	dis1[1] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		ll curDis = pq.top().first;
		pq.pop();
		if (dis1[node] < curDis) continue;
		for (auto& it : adj[node]) {
			int nxtNode = it.first;
			ll nxtDis = it.second + curDis;
			if (dis1[nxtNode] > nxtDis) {
				dis1[nxtNode] = nxtDis;
				pq.push({nxtDis, nxtNode});
			}
		}
	}
}

void bfsn() {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, n});
	disn[n] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		ll curDis = pq.top().first;
		pq.pop();
		if (disn[node] < curDis) continue;
		for (auto& it : radj[node]) {
			int nxtNode = it.first;
			ll nxtDis = it.second + curDis;
			if (disn[nxtNode] > nxtDis) {
				disn[nxtNode] = nxtDis;
				pq.push({nxtDis, nxtNode});
			}
		}
	}
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		radj[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	for (int i = 0; i <= n; i++) {
		dis1[i] = INF;
		disn[i] = INF;
	}
	bfs1();
	bfsn();
	ll ans = INF;
	for (auto& it : edges) {
		int u = it[0], v = it[1], w = it[2];
		ans = min(ans, dis1[u] + (w / 2) + disn[v]);
	}
	cout << ans;
	return 0;
}