// Problem Link - https://www.interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &a, int s) {
    int n = a.size();
    int MOD = 1000007;
    vector<vector<long long>> dp(2, vector<long long>(s + 5));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j == 0) {
                dp[i % 2][j] = 1;
            }
            else if (i == 0) {
                dp[i % 2][j] = 0;
            }
            else {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
                int left = j - a[i - 1];
                if (left >= 0) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[i % 2][left]) % MOD;
                }
            }
        }
    }
    return dp[n % 2][s];
}
