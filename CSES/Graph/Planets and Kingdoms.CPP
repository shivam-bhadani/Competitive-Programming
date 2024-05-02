/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

// Kosaraju's Algorithm

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> radj[N];
vector<int> vis(N);
stack<int> st;
vector<int> ans(N);

void dfs1(int node) {
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (vis[it] == 0) {
			dfs1(it);
		}
	}
	st.push(node);
}

void dfs2(int node, int kingdom) {
	vis[node] = 1;
	ans[node] = kingdom;
	for (auto& it : radj[node]) {
		if (vis[it] == 0) {
			dfs2(it, kingdom);
		}
	}
}

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs1(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	int countKingdoms = 0;
	while (!st.empty()) {
		int node = st.top();
		st.pop();
		if (vis[node] == 0) {
			++countKingdoms;
			dfs2(node, countKingdoms);
		}
	}
	cout << countKingdoms << '\n';
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}