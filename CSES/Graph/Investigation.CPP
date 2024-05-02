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
const ll INF = 1e18;
const int N = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
ll dis[N], cnt[N], minF[N], maxF[N];

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	for (int i = 0; i <= n; i++) {
		dis[i] = INF;
		minF[i] = INF;
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});
	dis[1] = 0;
	cnt[1] = 1;
	minF[1] = 0;
	maxF[1] = 0;
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
				cnt[nxtNode] = cnt[node];
				minF[nxtNode] = 1 + minF[node];
				maxF[nxtNode] = 1 + maxF[node];
				pq.push({nxtDis, nxtNode});
			}
			else if (dis[nxtNode] == nxtDis) {
				cnt[nxtNode] = (cnt[nxtNode] + cnt[node]) % MOD;
				minF[nxtNode] = min(minF[nxtNode], 1 + minF[node]);
				maxF[nxtNode] = max(maxF[nxtNode], 1 + maxF[node]);
			}
		}
	}
	cout << dis[n] << ' ' << cnt[n] << ' ' << minF[n] << ' ' << maxF[n];
	return 0;
}