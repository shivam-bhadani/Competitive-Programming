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

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
int vis[N], vis2[N], par[N];
int ok = 0, startVertex, endVertex;

int dfs(int node) {
	vis[node] = 1;
	vis2[node] = 1;
	for (auto& it : adj[node]) {
		if (!vis[it]) {
			par[it] = node;
			if (dfs(it)) {
				return 1;
			}
		}
		else if (vis2[it]) {
			startVertex = it;
			endVertex = node;
			return 1;
		}
	}
	vis2[node] = 0;
	return 0;
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int f = dfs(i);
			if (f) {
				ok = 1;
				int node = endVertex;
				ans.push_back(startVertex);
				while (node != startVertex) {
					ans.push_back(node);
					node = par[node];
				}
				ans.push_back(startVertex);
				reverse(all(ans));
				break;
			}
		}
	}
	if (!ok) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << (int)ans.size() << '\n';
	for (auto& x : ans) {
		cout << x << ' ';
	}
	return 0;
}