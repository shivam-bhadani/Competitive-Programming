class Solution {
public:
    long long INF = 1e15;
    int floydWarshall(int n, vector<int>& deleted, int maxDistance, vector<vector<long long>> dist) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (deleted[i] || deleted[j] || deleted[k]) continue;
                    if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (deleted[i] || deleted[j]) continue;
                if (dist[i][j] > maxDistance) {
                    return 0;
                }
            }
        }
        return 1;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto& x : roads) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            dist[u][v] = min(dist[u][v], (long long)w);
            dist[v][u] = min(dist[v][u], (long long)w);
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> deleted(n);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    deleted[j] = 1;
                }
            }
            if (floydWarshall(n, deleted, maxDistance, dist)) {
                ++ans;
            }
        }
        return ans;
    }
};