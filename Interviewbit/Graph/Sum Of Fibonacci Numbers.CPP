// Problem Link - https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int A) {
	vector<int> fab;
	fab.push_back(1);
	fab.push_back(1);
	int i = 1;
	while (1) {
		long long nxt = fab[i] + fab[i - 1];
		if (nxt <= A) {
			fab.push_back(nxt);
		}
		else break;
		i++;
	}
	int ans = 0;
	while (A) {
		auto it = upper_bound(fab.begin(), fab.end(), A);
		it--;
		A -= *it;
		ans++;
	}
	return ans;
}
