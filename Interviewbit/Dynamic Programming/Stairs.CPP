// Problem Link - https://www.interviewbit.com/problems/stairs/

int Solution::climbStairs(int n) {
	vector<int> dp(n + 5);
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
