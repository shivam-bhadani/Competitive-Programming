// Problem Link - https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

vector<vector<int> > Solution::solve(int K, vector<vector<int> > &a) {
	int n = a.size(), m = a[0].size();
	int dp[n][m][2];
	for (int k = 0; k <= K; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (k == 0) {
					dp[i][j][0] = a[i][j];
				}
				else {
					dp[i][j][k % 2] = a[i][j];
					if (i - 1 >= 0) {
						dp[i][j][k % 2] = max(dp[i][j][k % 2], dp[i - 1][j][(k + 1) % 2]);
					}
					if (i + 1 < n) {
						dp[i][j][k % 2] = max(dp[i][j][k % 2], dp[i + 1][j][(k + 1) % 2]);
					}
					if (j - 1 >= 0) {
						dp[i][j][k % 2] = max(dp[i][j][k % 2], dp[i][j - 1][(k + 1) % 2]);
					}
					if (j + 1 < m) {
						dp[i][j][k % 2] = max(dp[i][j][k % 2], dp[i][j + 1][(k + 1) % 2]);
					}
				}
			}
		}
	}
	vector<vector<int>> ans(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = dp[i][j][K % 2];
		}
	}
	return ans;
}
