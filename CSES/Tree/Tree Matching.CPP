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
vector<vector<int>> dp(N, vector<int>(2));

void dfs(int node, int par) {
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
	}
	for (auto& it : adj[node]) {
		dp[node][0] += max(dp[it][0], dp[it][1]);
	}
	vector<int> prefSum, sufSum;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		prefSum.push_back(max(dp[it][0], dp[it][1]));
		sufSum.push_back(max(dp[it][0], dp[it][1]));
	}
	for (int i = 1; i < prefSum.size(); i++) {
		prefSum[i] += prefSum[i - 1];
	}
	for (int i = sufSum.size() - 2; i >= 0; i--) {
		sufSum[i] += sufSum[i + 1];
	}
	int i = 0;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		int tmp = ((i - 1 >= 0) ? prefSum[i - 1] : 0) + (i + 1 < sufSum.size() ? sufSum[i + 1] : 0) + dp[it][0];
		dp[node][1] = max(dp[node][1], 1 + tmp);
		i++;
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
	dfs(1, -1);
	cout << max(dp[1][0], dp[1][1]);
}