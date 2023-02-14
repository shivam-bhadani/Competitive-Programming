// Problem Link - https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
	vector<vector<int>> dp(A.size() + 5, vector<int>(B.size() + 5));
	for (int i = 0; i <= A.size(); i++) {
		for (int j = 0; j <= B.size(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = max(i, j);
			}
			else {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
				}
			}
		}
	}
	return dp[A.size()][B.size()];
}
