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
int col[N];
int ok = 1;

void dfs(int node, int c) {
	if (!ok) return;
	col[node] = c;
	for (auto& it : adj[node]) {
		int nc = c ^ 3;
		if (col[it]) {
			if (col[it] != nc) {
				ok = 0;
				return;
			}
		}
		else {
			dfs(it, nc);
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
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!col[i]) {
			dfs(i, 1);
		}
	}
	if (!ok) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << col[i] << ' ';
	}
	return 0;
}