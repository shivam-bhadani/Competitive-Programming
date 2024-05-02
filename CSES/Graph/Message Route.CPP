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
int par[N];
int ok = 0;

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
	queue<int> q;
	q.push(1);
	par[1] = -1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == n) {
			ok = 1;
			break;
		}
		for (auto& it : adj[node]) {
			if (!par[it]) {
				par[it] = node;
				q.push(it);
			}
		}
	}
	if (!ok) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	int currNode = n;
	while (currNode != 1) {
		ans.push_back(currNode);
		currNode = par[currNode];
	}
	ans.push_back(1);
	reverse(all(ans));
	cout << (int)ans.size() << '\n';
	for (auto& x : ans) {
		cout << x << ' ';
	}
	return 0;
}