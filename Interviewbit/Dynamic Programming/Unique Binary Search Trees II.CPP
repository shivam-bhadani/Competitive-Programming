// Problem Link - https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int dp[30];
int solve(int n) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += solve(i - 1) * solve(n - i);
    }
    return dp[n] = ans;
}

int Solution::numTrees(int n) {
    memset(dp, -1, sizeof dp);
    int ans = solve(n);
    return ans;
}
