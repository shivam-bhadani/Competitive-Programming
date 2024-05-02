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

const int N = 2e5 + 5;

vector<int> adj[N];
int vis[N];
int par[N];
int ok = 0, startVertex, endVertex;

int dfs(int node, int _par) {
	vis[node] = 1;
	par[node] = _par;
	for (auto& it : adj[node]) {
		if (!vis[it]) {
			if (dfs(it, node)) {
				return 1;
			}
		}
		else if (it != _par) {
			startVertex = it;
			endVertex = node;
			return 1;
		}
	}
	return 0;
}

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int f = dfs(i, -1);
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