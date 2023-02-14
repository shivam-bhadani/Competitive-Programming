// Problem Link - https://www.interviewbit.com/problems/paint-house/

int Solution::solve(vector<vector<int> > &a) {
	int n = a.size();
	vector<vector<int>> dp(n + 5, vector<int>(3));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = a[i - 1][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = a[i - 1][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = a[i - 1][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	return min({dp[n][0], dp[n][1], dp[n][2]});
}
