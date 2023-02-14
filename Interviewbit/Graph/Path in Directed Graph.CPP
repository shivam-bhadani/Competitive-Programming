// Problem Link - https://www.interviewbit.com/problems/path-in-directed-graph/

int dfs(int node, int target, vector<int>& vis, vector<int> adj[]) {
    if (node == target) return 1;
    vis[node] = 1;
    int ans = 0;
    for (auto& it : adj[node]) {
        if (vis[it] == 0) {
            ans |= dfs(it, target, vis, adj);
        }
    }
    return ans;
}

int Solution::solve(int n, vector<vector<int> > &edge) {
    vector<int> adj[n + 5];
    for (auto& x : edge) {
        adj[x[0]].push_back(x[1]);
    }
    vector<int> vis(n + 5);
    return dfs(1, n, vis, adj);
}
