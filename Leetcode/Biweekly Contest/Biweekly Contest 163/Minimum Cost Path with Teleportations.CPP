class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> d(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> q;
        d[0][0][0] = 0;
        q.push({0, 0, 0, 0});
        vector<pair<int, pair<int, int>>> v;
        v.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back({grid[i][j], {i, j}});
            }
        }
        sort(v.begin(), v.end());
        vector<int> f(k + 1, 0);
        while (!q.empty()) {
            auto [c, i, j, t] = q.top();
            q.pop();
            if (i == m - 1 && j == n - 1) return c;
            if (c != d[i][j][t]) continue;
            if (i + 1 < m) {
                int nc = c + grid[i + 1][j];
                if (nc < d[i + 1][j][t]) {
                    d[i + 1][j][t] = nc;
                    q.push({nc, i + 1, j, t});
                }
            }
            if (j + 1 < n) {
                int nc = c + grid[i][j + 1];
                if (nc < d[i][j + 1][t]) {
                    d[i][j + 1][t] = nc;
                    q.push({nc, i, j + 1, t});
                }
            }
            if (t < k) {
                while (f[t] < (int)v.size() && v[f[t]].first <= grid[i][j]) {
                    auto [val, pos] = v[f[t]];
                    int x = pos.first, y = pos.second;
                    if (c < d[x][y][t + 1]) {
                        d[x][y][t + 1] = c;
                        q.push({c, x, y, t + 1});
                    }
                    f[t]++;
                }
            }
        }
        return -1;
    }
};