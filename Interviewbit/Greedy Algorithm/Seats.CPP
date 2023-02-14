// Problem Link - https://www.interviewbit.com/problems/seats/

int Solution::seats(string s) {
	int ind = 0;
	int cnt = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		cnt += (s[i] == 'x');
	}
	cnt = (cnt + 1) / 2;
	int cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			cnt1++;
			if (cnt1 == cnt) {
				ind = i;
				break;
			}
		}
	}
	int ans = 0;
	const int MOD = 10000003;
	int i = ind - 1;
	int ind1 = ind - 1;
	while (i >= 0) {
		if (s[i] == 'x') {
			ans = (ans + (ind1 - i)) % MOD;
			ind1--;
		}
		i--;
	}
	ind1 = ind + 1;
	i = ind + 1;
	while (i < n) {
		if (s[i] == 'x') {
			ans = (ans + (i - ind1)) % MOD;
			ind1++;
		}
		i++;
	}
	return ans;
}
