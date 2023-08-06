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
vector<int> depth(N);
vector<int> ans(N);

void dfs_depth(int node, int par) {
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs_depth(it, node);
		depth[node] = max(depth[node], 1 + depth[it]);
	}
}

void dfs(int node, int par, int par_ans) {
	vector<int> prefMax, sufMax;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		prefMax.push_back(depth[it]);
		sufMax.push_back(depth[it]);
	}
	for (int i = 1; i < prefMax.size(); i++) {
		prefMax[i] = max(prefMax[i - 1], prefMax[i]);
	}
	for (int i = sufMax.size() - 2; i >= 0; i--) {
		sufMax[i] = max(sufMax[i + 1], sufMax[i]);
	}
	ans[node] = 1 + max(par_ans, prefMax.empty() ? -1 : prefMax.back());
	int ind = 0;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		int pref = (ind == 0 ? -1 : prefMax[ind - 1]);
		int suf = (ind == sufMax.size() - 1 ? -1 : sufMax[ind + 1]);
		int x = 1 + max(par_ans, max(pref, suf));
		++ind;
		dfs(it, node, x);
	}
}

int main() {
	IOS
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_depth(1, -1);
	dfs(1, -1, -1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}