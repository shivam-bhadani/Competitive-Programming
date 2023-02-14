int Solution::bulbs(vector<int> &a) {
	int n = a.size();
	int ans = 0;
	for (auto& x : a) {
		if (x ^ (ans & 1)) {
			continue;
		}
		ans++;
	}
	return ans;
}
