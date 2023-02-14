// Problem Link - https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int> > &a) {
	int n = a.size(), m = a[0].size();
	vector<vector<int>> dp(n, vector<int>(m)); // minimum health when he enter [i][j]
	dp[n - 1][m - 1] = max(1, 1 - a[n - 1][m - 1]);

	for (int i = n - 2; i >= 0; i--) {
		dp[i][m - 1] = max(dp[i + 1][m - 1] - a[i][m - 1], 1);
	}
	for (int i = m - 2; i >= 0; i--) {
		dp[n - 1][i] = max(dp[n - 1][i + 1] - a[n - 1][i], 1);
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			int d = max(dp[i + 1][j] - a[i][j], 1);
			int r = max(dp[i][j + 1] - a[i][j], 1);
			dp[i][j] = min(r, d);
		}
	}
	return dp[0][0];
}
