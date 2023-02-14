// Problem Link - https://www.interviewbit.com/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &a) {
    int n = a.size();
    int s = 0;
    for (auto& x : a) s += x;
    vector<vector<int>> dp(n + 5, vector<int>(s + 5));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j];
                int lft = j - a[i - 1];
                if (lft >= 0) {
                    dp[i][j] |= dp[i - 1][lft];
                }
            }
        }
    }
    vector<int> possible_sum(s + 5);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            possible_sum[j] |= dp[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= s; i++) {
        if (possible_sum[i]) {
            int diff = abs(i - abs(s - i));
            ans = min(ans, diff);
        }
    }
    return ans;
}
