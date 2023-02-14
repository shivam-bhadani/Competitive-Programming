// Problem Link - https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &a) {
	int n = a.size();
	vector<int> dp(n + 5, INT_MAX);
	dp[0] = INT_MIN;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (dp[j - 1] < a[i] && dp[j] > a[i]) {
			dp[j] = a[i];
		}
	}
	for (int i = n; i >= 0; i--) {
		if (dp[i] != INT_MAX) return i;
	}
	return 0;
}
