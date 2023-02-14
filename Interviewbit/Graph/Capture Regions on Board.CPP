// Problem Link - https://www.interviewbit.com/problems/capture-regions-on-board/

void dfs(int x, int y, vector<vector<char>>& a) {
    vector<int> dx = { -1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    a[x][y] = '*';
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 'O') {
            dfs(nx, ny, a);
        }
    }
}

void Solution::solve(vector<vector<char> > &a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 'O')
            dfs(i, 0, a);
        if (a[i][m - 1] == 'O')
            dfs(i, m - 1, a);
    }
    for (int j = 0; j < m; j++) {
        if (a[0][j] == 'O')
            dfs(0, j, a);
        if (a[n - 1][j] == 'O')
            dfs(n - 1, j, a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                a[i][j] = 'O';
            }
            else {
                a[i][j] = 'X';
            }
        }
    }
}
