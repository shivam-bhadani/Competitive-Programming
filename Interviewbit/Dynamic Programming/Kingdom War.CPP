int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[n - 1][m - 1] = a[n - 1][m - 1];
    for (int j = m - 2; j >= 0; j--) {
        dp[n - 1][j] = a[n - 1][j] + dp[n - 1][j + 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        dp[i][m - 1] = a[i][m - 1] + dp[i + 1][m - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            dp[i][j] = a[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
