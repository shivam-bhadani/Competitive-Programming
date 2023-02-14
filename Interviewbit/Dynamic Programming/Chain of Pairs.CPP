// Problem Link - https://www.interviewbit.com/problems/chain-of-pairs/

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    vector<int> dp(n + 5, 1);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j][1] < a[i][0]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
