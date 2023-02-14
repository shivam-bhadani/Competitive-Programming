// Problem Link - https://www.interviewbit.com/problems/different-bits-sum-pairwise/

int Solution::cntBits(vector<int> &nums) {
	int n = 33;
	vector<int> bit(n);
	for (int i = 0; i < n; i++) {
		for (auto& x : nums) {
			if ((1LL << i)&x) {
				bit[i]++;
			}
		}
	}
	long long ans = 0;
	const int MOD = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		ans += (bit[i] * (nums.size() - bit[i])) % MOD;
	}
	return (2LL * ans) % MOD;
}
