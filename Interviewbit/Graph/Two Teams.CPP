const int N = 100005;
vector<int> adj[N];
int vis[N]; // store color of node
// we have to make the graph bipartite
int ans = 1;

// Problem Link - https://www.interviewbit.com/problems/two-teams/

void dfs(int node, int par, int col) {
    if (!ans) return;
    vis[node] = col;
    for (auto& it : adj[node]) {
        if (ans == 0) return;
        if (vis[it] == -1) {
            dfs(it, node, !col);
        }
        else {
            if (it == par) continue;
            else {
                if (vis[it] == col) {
                    ans = 0;
                    return;
                }
            }
        }
    }
}

int Solution::solve(int n, vector<vector<int> > &B) {
    ans = 1;
    for (int i = 0; i <= n; i++) {
        vis[i] = -1;
        adj[i].clear();
    }
    for (auto& x : B) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    for (int i = 1; i <= n; i++) {
        if (ans == 0) return ans;
        if (vis[i] == -1) {
            dfs(i, -1, 1);
        }
    }
    return ans;
}