// Problem Link - https://www.interviewbit.com/problems/egg-drop-problem/

int Solution::solve(int n, int k) {
    vector<vector<int>> dp(n + 5, vector<int>(k + 5));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= k; j++)
        dp[1][j] = j;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            int lo = 1, hi = j;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int x = dp[i - 1][mid - 1];
                int y = dp[i][j - mid];
                if (x < y) {
                    dp[i][j] = min(dp[i][j], 1 + y);
                    lo = mid + 1;
                }
                else {
                    dp[i][j] = min(dp[i][j], 1 + x);
                    hi = mid - 1;
                }
            }
        }
    }
    return dp[n][k];
}
