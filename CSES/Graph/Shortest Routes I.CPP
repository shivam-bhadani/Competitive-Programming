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

const ll INF = 1e18;
const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];
ll dis[N];

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});
	dis[1] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		ll curDis = pq.top().first;
		pq.pop();
		if (dis[node] < curDis) continue;
		for (auto& it : adj[node]) {
			int nxtNode = it.first;
			ll nxtDis = it.second + curDis;
			if (dis[nxtNode] > nxtDis) {
				dis[nxtNode] = nxtDis;
				pq.push({nxtDis, nxtNode});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
	return 0;
}