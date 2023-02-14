// Problem Link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int Solution::maxProfit(const vector<int> &a) {
	int n = a.size(), ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] > a[i]) {
			ans += a[i + 1] - a[i];
		}
	}
	return ans;
}
