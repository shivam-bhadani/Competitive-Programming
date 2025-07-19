class Solution {
public:
    bool topoSort(int n, vector<int>& topo, vector<int> adj[]) {
        vector<int> indeg(n);
        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                ++indeg[it];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int no_of_node = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            ++no_of_node;
            for (auto& it : adj[node]) {
                --indeg[it];
                if (indeg[it] == 0) q.push(it);
            }
        }
        return no_of_node == n;
    }
    int possible(int mid, vector<int>& topo, vector<pair<long long, long long>> radj[], vector<bool>& online, long long k) {
        int n = (int)topo.size();
        long long maxVal = 1e15;
        vector<long long> dp(n, maxVal);
        dp[0] = 0;
        for (auto& i : topo) {
            if (online[i] == 0) continue;
            for (auto& it : radj[i]) {
                int from = it.first;
                long long cost = it.second;
                if (online[from] && cost >= mid && dp[from] != maxVal && dp[from] + cost <= k) {
                    dp[i] = min(dp[i], dp[from] + cost);
                }
            }
        }
        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = (int)online.size();
        vector<pair<long long, long long>> radj[n];
        vector<int> adj[n];
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            radj[v[1]].push_back({v[0], v[2]});
        }
        vector<int> topo;
        topoSort(n, topo, adj);
        int lo = 0, hi = 1e9;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (possible(mid, topo, radj, online, k)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};