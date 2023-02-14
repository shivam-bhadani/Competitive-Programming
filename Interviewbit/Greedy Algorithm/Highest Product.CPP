// Problem Link - https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &a) {
	if (a.size() < 3) return 0;
	int n = a.size();
	sort(a.begin(), a.end());
	int ans = a[n - 1] * a[n - 2] * a[n - 3];
	ans = max(ans, a[n - 1] * a[0] * a[1]);
	return ans;
}
