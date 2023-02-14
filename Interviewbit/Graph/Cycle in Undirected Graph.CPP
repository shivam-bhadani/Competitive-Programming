// Problem Link - https://www.interviewbit.com/problems/cycle-in-undirected-graph/

const int N = 3e5 + 5;
vector<int> adj[N];
int vis[N];

int dfs(int node, int par) {
    vis[node] = 1;
    for (auto& it : adj[node]) {
        if (vis[it] == 0) {
            if (dfs(it, node)) return 1;
        }
        else if (vis[it] == 1 && it != par) {
            return 1;
        }
    }
    return 0;
}

int Solution::solve(int n, vector<vector<int> > &B) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
    }
    for (auto& x : B) {
        if (x[0] == x[1]) continue;
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            int ans = dfs(i, -1);
            if (ans == 1) return ans;
        }
    }
    return 0;
}
