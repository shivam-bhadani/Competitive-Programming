// Problem Link - https://www.interviewbit.com/problems/palindrome-partitioning-ii/

int dp[505];
int solve(int ind, vector<vector<int>>& isPal, int n) {
    if (ind >= n) return 0;
    if (dp[ind] != -1) return dp[ind];
    int &ans = dp[ind];
    if (isPal[ind][n - 1]) {
        ans = 0;
        return ans;
    }
    ans = INT_MAX;
    for (int i = ind; i < n; i++) {
        if (isPal[ind][i]) {
            ans = min(ans, 1 + solve(i + 1, isPal, n));
        }
    }
    return ans;
}

int Solution::minCut(string s) {
    int n = s.size();
    memset(dp, -1, sizeof dp);
    vector<vector<int>> isPal(n, vector<int>(n));
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) {
                isPal[i][j] = 1;
            }
            else if (g == 1) {
                isPal[i][j] = s[i] == s[j];
            }
            else {
                if (s[i] == s[j]) {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
                else {
                    isPal[i][j] = 0;
                }
            }
        }
    }
    return solve(0, isPal, n);
}
