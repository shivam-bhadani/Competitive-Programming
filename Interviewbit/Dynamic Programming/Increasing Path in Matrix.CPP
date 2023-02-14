// Problem Link - https://www.interviewbit.com/problems/increasing-path-in-matrix/

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[n - 1][m - 1] = 1;
    for (int j = m - 2; j >= 0; j--) {
        if (a[n - 1][j + 1] > a[n - 1][j] && dp[n - 1][j + 1] != INT_MAX)
            dp[n - 1][j] = 1 + dp[n - 1][j + 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i][m - 1] < a[i + 1][m - 1] && dp[i + 1][m - 1] != INT_MAX)
            dp[i][m - 1] = 1 + dp[i + 1][m - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (dp[i][j + 1] != INT_MAX && a[i][j] < a[i][j + 1]) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
            }
            if (dp[i + 1][j] != INT_MAX && a[i][j] < a[i + 1][j]) {
                dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
            }
        }
    }
    return dp[0][0] == INT_MAX ? -1 : dp[0][0];
}
