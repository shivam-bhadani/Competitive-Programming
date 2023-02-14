// Problem Link - https://www.interviewbit.com/problems/coins-in-a-line/

int Solution::maxcoin(vector<int> &a) {
	int n = a.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int g = 0; g < n; g++) {
		for (int i = 0, j = g; j < n; i++, j++) {
			if (g == 0) {
				dp[i][j] = a[i];
			}
			else if (g == 1) {
				dp[i][j] = max(a[i], a[i + 1]);
			}
			else {
				int x = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
				int y = a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
				dp[i][j] = max(x, y);
			}
		}
	}
	return dp[0][n - 1];
}
