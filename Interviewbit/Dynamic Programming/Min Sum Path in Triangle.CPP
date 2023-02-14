// Problem LInk - https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int Solution::minimumTotal(vector<vector<int> > &a) {
    int n = a.size(), m = a[n - 1].size();
    vector<vector<int>> dp(n, vector<int>(m, 1000000));
    for (int j = m - 1; j >= 0; j--) {
        dp[n - 1][j] = a[n - 1][j];
    }
    m--;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = a[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
        m--;
    }
    return dp[0][0];
}
