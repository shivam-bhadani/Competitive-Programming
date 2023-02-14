// Problem Link - https://www.interviewbit.com/problems/subset-sum-problem/

int Solution::solve(vector<int> &a, int s) {
	int n = a.size();
	vector<vector<int>> dp(n + 5, vector<int>(s + 5));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else if (i == 0) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i - 1][j];
				int left = j - a[i - 1];
				if (left >= 0) {
					dp[i][j] |= dp[i - 1][left];
				}
			}
		}
	}
	return dp[n][s];
}
