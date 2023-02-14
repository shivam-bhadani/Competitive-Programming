// Problem Link - https://www.interviewbit.com/problems/ways-to-decode/

int Solution::numDecodings(string s) {
	int n = s.size();
	if (s[0] == '0') return 0;
	const int MOD = 1e9 + 7;
	vector<long long> dp(n + 5);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 1] == '0' && (s[i - 2] > '2' || s[i - 2] == '0')) return 0;
		else if (s[i - 1] == '0') {
			dp[i] = dp[i - 2];
		}
		else if (s[i - 2] == '1') {
			dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
		}
		else if ((s[i - 1] >= '1' && s[i - 1] <= '6') && (s[i - 2] == '2')) {
			dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	return dp[n];
}
