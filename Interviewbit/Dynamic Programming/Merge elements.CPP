// Problem Link - https://www.interviewbit.com/problems/merge-elements/

int Solution::solve(vector<int> &a) {
    int n = a.size();
    vector<int> prefSum(n + 5);
    for (int i = 0; i < n; i++) {
        prefSum[i + 1] = prefSum[i] + a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) {
                dp[i][j] = 0;
            }
            else if (g == 1) {
                dp[i][j] = a[i] + a[j];
            }
            else {
                int val = INT_MAX;
                for (int k = i; k < j; k++) {
                    // i to k, k+1, j
                    int now = prefSum[j + 1] - prefSum[i];
                    now += dp[i][k] + dp[k + 1][j];
                    val = min(val, now);
                }
                dp[i][j] = val;
            }
        }
    }
    return dp[0][n - 1];
}
