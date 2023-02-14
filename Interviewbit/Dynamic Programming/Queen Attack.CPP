// Problem Link - https://www.interviewbit.com/problems/queen-attack/

vector<int> dx = { -1, 0, 1, 0, -1, -1, 1, 1};
vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};

int rec(int x, int y, int k, vector<vector<vector<int>>>& dp, vector<string>& a) {
    int &ans = dp[x][y][k];
    if (ans != -1) return ans;
    int n = a.size(), m = a[0].size();
    ans = 0;
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (a[nx][ny] == '1') ans++;
        else ans += rec(nx, ny, k, dp, a);
    }
    return ans;
}

vector<vector<int> > Solution::queenAttack(vector<string> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<vector<int>>> dp(n + 5, vector<vector<int>>(m + 5, vector<int>(10, -1)));
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                cnt += rec(i, j, k, dp, a);
            }
            ans[i][j] = cnt;
        }
    }
    return ans;
}
