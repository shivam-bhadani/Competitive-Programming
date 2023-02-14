// Problem Link - https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if (n <= 2) {
        return n;
    }
    vector<vector<int>> dp(n, vector<int>(n, 2));
    map<int, int> pos;
    int ans = 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int need = 2 * A[i] - A[j];
            if (pos.count(need)) {
                dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
            }
            ans = max(dp[i][j], ans);
        }
        pos[A[i]] = i;
    }

    return ans;
}
