// Problem Link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &a) {
	int n = a.size();
	if (n == 0) return 0;
	int ans = 0;
	int prefMin = a[0];
	for (auto& x : a) {
		prefMin = min(prefMin, x);
		ans = max(ans, x - prefMin);
	}
	return ans;
}
