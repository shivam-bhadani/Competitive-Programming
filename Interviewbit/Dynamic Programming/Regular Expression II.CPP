// Problem Link - https://www.interviewbit.com/problems/regular-expression-ii/

int Solution::isMatch(const string s, const string p) {
	int np = p.size(), ns = s.size();
	vector<vector<bool>> dp(np + 1, vector<bool>(ns + 1));
	for (int i = 0; i <= np; i++) {
		for (int j = 0; j <= ns; j++) {
			if (i == 0 && j == 0) dp[i][j] = true;
			else if (i == 0) dp[i][j] = false;
			else if (j == 0) {
				if (p[i - 1] == '*') dp[i][j] = dp[i][j] = dp[i - 2][j];
				else dp[i][j] = false;
			}
			else {
				if (p[i - 1] == s[j - 1] || p[i - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
				else if (p[i - 1] == '*') {
					dp[i][j] = dp[i - 2][j];
					if (p[i - 2] == '.' || p[i - 2] == s[j - 1]) dp[i][j] = dp[i][j] | dp[i][j - 1];
				}
				else dp[i][j] = false;
			}
		}
	}
	return dp[np][ns];
}
