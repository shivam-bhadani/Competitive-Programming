/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 200005;

vector<int> adj[N];
vector<int> depth(N);
vector<int> diameter(N);

void dfs_depth(int node, int par) {
	int mxChildDepth = 0;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs_depth(it, node);
		mxChildDepth = max(mxChildDepth, depth[it]);
	}
	depth[node] = 1 + mxChildDepth;
}

void dfs(int node, int par) {
	int best = 0;
	vector<int> childDepth;
	int leaf = 1;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
		leaf = 0;
		best = max(best, diameter[it]);
		childDepth.push_back(depth[it]);
	}
	if (leaf) {
		diameter[node] = 0;
		return;
	}
	sort(childDepth.begin(), childDepth.end());
	if (childDepth.size() == 1) {
		best = max(best, childDepth[0]);
	}
	else {
		best = max(best, childDepth.back() + childDepth[childDepth.size() - 2]);
	}
	diameter[node] = best;
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
	dfs(1, -1);
	cout << diameter[1];
}