/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

vector<int> adj[N];

vector<ll> sub(N);
vector<ll> ans(N);

void dfs1(int node, int par) {
	sub[node] = 1;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs1(it, node);
		sub[node] += sub[it];
		ans[node] += sub[it] + ans[it];
	}
}

void dfs2(int node, int par) {
	for (auto& it : adj[node]) {
		if (it == par) continue;
		ans[it] += ans[node] - sub[it] - ans[it] + sub[1] - sub[it];
		dfs2(it, node);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}