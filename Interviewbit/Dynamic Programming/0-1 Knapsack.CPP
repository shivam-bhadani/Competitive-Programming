// Problem Link - https://www.interviewbit.com/problems/0-1-knapsack/

int Solution::solve(vector<int> &val, vector<int> &wt, int w) {
    int n = val.size();
    vector<vector<int>> dp(n + 5, vector<int>(w + 5));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            int left = j - wt[i - 1];
            if (left >= 0) {
                dp[i][j] = max(dp[i][j], val[i - 1] + dp[i - 1][left]);
            }
        }
    }
    return dp[n][w];
}
