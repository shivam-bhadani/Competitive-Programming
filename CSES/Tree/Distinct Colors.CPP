/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 2e5 + 5;

vector<int> adj[N];
set<int> st[N];
vector<int> c(N), ans(N);

void dfs(int node, int par) {
	st[node].insert(c[node]);
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
		if (st[node].size() < st[it].size()) {
			swap(st[node], st[it]);
		}
		for (auto& x : st[it]) {
			st[node].insert(x);
		}
	}
	ans[node] = st[node].size();
}

int main() {
	IOS
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}