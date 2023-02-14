// Problem Link - https://www.interviewbit.com/problems/water-flow/

void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int> > &a) {
    vis[x][y] = 1;
    vector<int> dx = { -1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < vis.size() && ny >= 0 && ny < vis[0].size() && vis[nx][ny] == 0) {
            if (a[nx][ny] >= a[x][y])
                dfs(nx, ny, vis, a);
        }
    }
}


int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis1(n, vector<int>(m));
    vector<vector<int>> vis2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        if (vis1[i][0] == 0) {
            dfs(i, 0, vis1, a);
        }
        if (vis2[i][m - 1] == 0) {
            dfs(i, m - 1, vis2, a);
        }
    }
    for (int j = 0; j < m; j++) {
        if (vis1[0][j] == 0) {
            dfs(0, j, vis1, a);
        }
        if (vis2[n - 1][j] == 0) {
            dfs(n - 1, j, vis2, a);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis1[i][j] && vis2[i][j]) ans++;
        }
    }
    return ans;
}
