class Solution {
public:
    long long cache[20005][2];
    long long dp(int node, int par, int f, vector<int> adj[], vector<int>& val) {
        if (node != 0 && adj[node].size() == 1) {
            return f ? 0 : val[node];
        }
        if (cache[node][f] != -1) {
            return cache[node][f];
        }
        long long leave = 0, not_leave = 0;
        for (auto& it : adj[node]) {
            if (it == par) continue;
            leave += dp(it, node, 0, adj, val);
            not_leave += dp(it, node, f, adj, val);
        }
        return cache[node][f] = max(leave, val[node] + not_leave);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        memset(cache, -1, sizeof cache);
        int n = values.size();
        vector<int> adj[n];
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dp(0, -1, 1, adj, values);
    }
};