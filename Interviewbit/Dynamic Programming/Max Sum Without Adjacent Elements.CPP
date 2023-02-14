// Problem Link - https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int Solution::adjacent(vector<vector<int> > &a) {
	int n = a[0].size();
	vector<vector<int>> dp(n + 5, vector<int>(2));
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(a[0][i - 1], a[1][i - 1]) + dp[i - 1][0];
	}
	return max(dp[n][0], dp[n][1]);
}
