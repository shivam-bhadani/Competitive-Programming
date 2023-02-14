// Problem Link - https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
	int n = a.size(), m = a[0].size();
	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = a[0][0] != 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				dp[i][j] = 0;
				continue;
			}
			if (i - 1 >= 0 && a[i - 1][j] != 1) {
				dp[i][j] = dp[i - 1][j];
			}
			if (j - 1 >= 0 && a[i][j - 1] != 1) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	return dp[n - 1][m - 1];
}
