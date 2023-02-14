// Problem Link - https://www.interviewbit.com/problems/permutation-swaps/

const int N = 100005;
vector<int> adj[N];
int vis[N];

void dfs(int node, vector<int>& track) {
	track.push_back(node);
	vis[node] = 1;
	for (auto& it : adj[node]) {
		if (vis[it] == 0) {
			dfs(it, track);
		}
	}
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
	int n = A.size();
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		adj[i].clear();
	}
	for (auto& x : C) {
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vector<int> track;
			dfs(i, track);
			vector<int> first, second;
			for (auto& ind : track) {
				first.push_back(A[ind - 1]);
				second.push_back(B[ind - 1]);
			}
			sort(first.begin(), first.end());
			sort(second.begin(), second.end());
			if (first != second) return 0;
		}
	}
	return 1;
}
