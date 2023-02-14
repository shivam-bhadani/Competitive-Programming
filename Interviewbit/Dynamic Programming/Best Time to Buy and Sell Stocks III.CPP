// Problem Link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &a) {
	int n = a.size();
	vector<int> dp1(n + 5);
	int prefMin = INT_MAX;
	for (int i = 1; i <= n; i++) {
		prefMin = min(prefMin, a[i - 1]);
		dp1[i] = max(dp1[i - 1], a[i - 1] - prefMin);
	}
	vector<int> dp2(n + 5);
	int sufMax = INT_MIN;
	for (int i = n; i >= 1; i--) {
		sufMax = max(sufMax, a[i - 1]);
		dp2[i] = max(dp2[i + 1], sufMax - a[i - 1]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp1[i]);
		ans = max(ans, dp2[i]);
		ans = max(ans, dp1[i] + dp2[i]);
	}
	return ans;
}
