// Problem Link - https://www.interviewbit.com/problems/arrange-ii/

int Solution::arrange(string s, int k) {
    int n = s.size();
    vector<vector<long long>> dp(n + 5, vector<long long>(k + 5, INT_MAX));
    // [i][j] -> stores min ans upto i-th index by doing k partition
    if (n < k) return -1;
    int b = 0, w = 0;
    for (int i = 0; i < n; i++) {
        b += (s[i] == 'B');
        w += (s[i] == 'W');
        dp[i][1] = w * b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= k; j++) {
            int bl = 0, wt = 0;
            for (int x = i; x >= 0; x--) {
                bl += (s[x] == 'B');
                wt += (s[x] == 'W');
                if (j - 1 <= x) {
                    dp[i][j] = min(dp[i][j], ((x - 1 >= 0) ? dp[x - 1][j - 1] : 0) + bl * wt);
                }
            }
        }
    }
    return dp[n - 1][k] == INT_MAX ? -1 : dp[n - 1][k];
}
