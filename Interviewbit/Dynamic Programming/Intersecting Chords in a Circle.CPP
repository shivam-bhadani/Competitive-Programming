// Problem Link - https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

int Solution::chordCnt(int n) {
	// catlan no.
	vector<long long> dp(n + 5);
	const int MOD = 1e9 + 7;
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int j = i - 1;
		int k = 0;
		while (k < i) {
			dp[i] = (dp[i] + (dp[j] * dp[k])) % MOD;
			j--; k++;
		}
	}
	return dp[n];
}
