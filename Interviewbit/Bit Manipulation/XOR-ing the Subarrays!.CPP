// Problem Link - https://www.interviewbit.com/problems/xor-ing-the-subarrays/

int Solution::solve(vector<int> &a) {
	int n = a.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		long long cnt = (i + 1) * (n - i);
		if (cnt & 1) ans ^= a[i];
	}
	return ans;
}
