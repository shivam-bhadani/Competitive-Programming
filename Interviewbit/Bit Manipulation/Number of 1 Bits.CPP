int Solution::numSetBits(unsigned int A) {
	int cnt = 0;
	for (int i = 0; i <= 32; i++) {
		if ((1LL << i)&A) cnt++;
	}
	return cnt;
}
