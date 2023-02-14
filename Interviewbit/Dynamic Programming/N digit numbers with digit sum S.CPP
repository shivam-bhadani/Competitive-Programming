// Problem Link - https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

const int MOD = 1e9 + 7;

int rec(vector<vector<int>> &dp, int id, int sum) {
    if (sum < 0) return 0;
    if (id == 0 && sum == 0) return 1;
    if (id == 0) return 0;

    if (dp[id][sum] != -1) return dp[id][sum];

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += rec(dp, id - 1, sum - i);
        ans %= MOD;
    }
    return dp[id][sum] = ans;
}

int Solution::solve(int A, int B) {
    int ans = 0;
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, -1));
    for (int i = 1; i < 10; i++) {
        ans += rec(dp, A - 1, B - i);
        ans %= MOD;
    }
    return ans;
}