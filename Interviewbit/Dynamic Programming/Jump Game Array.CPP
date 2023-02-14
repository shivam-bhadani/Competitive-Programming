// Problem Link - https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n + 5);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (i + a[i] >= n - 1) {
            dp[i] = 1;
            continue;
        }
        for (int j = i + 1; j <= i + a[i]; j++) {
            dp[i] |= dp[j];
        }
    }
    return dp[0];
}
