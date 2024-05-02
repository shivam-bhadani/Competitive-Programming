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

// Euler Path
// Hierholzer's Algorithm

const int N = 2e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
int see[N], in[N], out[N];
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
		++out[u];
		++in[v];
	}
	if (out[1] != in[1] + 1 || in[n] != out[n] + 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 2; i < n; i++) {
		if (in[i] != out[i]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	dfs(1);
	if ((int)ans.size() != m + 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	reverse(all(ans));
	for (auto& x : ans) {
		cout << x << " ";
	}
}