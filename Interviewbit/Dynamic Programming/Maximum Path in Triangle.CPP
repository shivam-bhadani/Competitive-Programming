// Problem Link - https://www.interviewbit.com/problems/maximum-path-in-triangle/

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        dp[n - 1][j] = a[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = a[i][j] + dp[i + 1][j];
            if (j + 1 < m) {
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i + 1][j + 1]);
            }
        }
    }
    int ans = INT_MIN;
    for (int j = 0; j < m; j++) {
        ans = max(ans, dp[0][j]);
    }
    return ans;
}
