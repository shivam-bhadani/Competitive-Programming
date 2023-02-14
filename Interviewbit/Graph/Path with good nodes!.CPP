// Problem Link - https://www.interviewbit.com/problems/path-with-good-nodes/

int ans = 0;

void dfs(int node, int par, int sum, int limit, vector<int> adj[], vector<int>& A) {
	if (adj[node].size() == 1) {
		if (sum <= limit) ans++;
		return;
	}
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node, sum + A[it - 1], limit, adj, A);
	}
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
	int n = A.size();
	ans = 0;
	vector<int> adj[n + 5];
	for (auto& x : B) {
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}
	dfs(1, -1, A[0], C, adj, A);
	return ans;
}
