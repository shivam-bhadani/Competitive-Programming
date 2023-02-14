// Problem Link - https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int A) {
	unsigned int ans = 0;
	long long x = 31;
	for (int i = 0; i <= 31; i++) {
		if ((1LL << i) & A) {
			ans |= (1LL << x);
		}
		x--;
	}
	return ans;
}
