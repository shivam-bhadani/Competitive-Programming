// Problem Link - https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int Solution::minPathSum(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = a[i][0] + dp[i - 1][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = a[0][j] + dp[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n - 1][m - 1];
}
