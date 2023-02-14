// Problem Link - https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A.size();
	int ans = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		ans = min(ans, A[i] ^ A[i + 1]);
	}
	return ans;
}
