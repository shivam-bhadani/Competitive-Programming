// Problem Link - https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string s1, string s2, string s3) {
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n + 5, vector<int>(m + 5));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			else if (i == 0) {
				dp[i][j] = s2[j - 1] == s3[i + j - 1] ? dp[i][j - 1] : 0;
			}
			else if (j == 0) {
				dp[i][j] = s1[i - 1] == s3[i + j - 1] ? dp[i - 1][j] : 0;
			}
			else {
				if (s1[i - 1] == s3[i + j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				if (s2[j - 1] == s3[i + j - 1]) {
					dp[i][j] |= dp[i][j - 1];
				}
			}
		}
	}
	return dp[n][m];
}
