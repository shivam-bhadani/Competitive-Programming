// Problem Link - https://www.interviewbit.com/problems/cycle-in-directed-graph/

bool dfs(int node, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[]) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto& it : adj[node]) {
        if (vis[it] == 0) {
            if (dfs(it, vis, dfsVis, adj)) return true;
        }
        else if (dfsVis[it]) return true;
    }
    dfsVis[node] = 0;
    return false;
}

int Solution::solve(int V, vector<vector<int> > &B) {
    vector<int> adj[V + 5];
    for (auto& x : B) {
        adj[x[0]].push_back(x[1]);
    }
    vector<int> vis(V + 5), dfsVis(V + 5);
    for (int i = 1; i <= V; i++) {
        if (vis[i] == 0) {
            int ans = dfs(i, vis, dfsVis, adj);
            if (ans) return true;
        }
    }
    return false;
}
