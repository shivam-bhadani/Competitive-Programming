class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, long long &sum) {
        int n = (int)grid.size(), m = grid[0].size();
        sum += grid[r][c];
        vis[r][c] = 1;
        vector<int> dx = { -1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 0 && vis[nr][nc] == 0) {
                dfs(nr, nc, grid, vis, sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && vis[i][j] == 0) {
                    long long sum = 0;
                    dfs(i, j, grid, vis, sum);
                    cout << i << ' ' << j << ' ' << sum << endl;
                    if (sum % k == 0) ++ans;
                }
            }
        }
        return ans;
    }
};