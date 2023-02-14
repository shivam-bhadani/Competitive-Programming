// Problem Link - https://www.interviewbit.com/problems/largest-permutation/

vector<int> Solution::solve(vector<int> &a, int b) {
	int n = a.size();
	vector<int> mp(n + 5);
	for (int i = 0; i < n; i++) {
		mp[a[i]] = i;
	}
	int should = n;
	for (int i = 0; i < n; i++) {
		if (a[i] == should) {
			should--;
			continue;
		}
		if (b) {
			int ind = mp[should];
			mp[should] = i;
			mp[a[i]] = ind;
			swap(a[i], a[ind]);
			b--;
		}
		should--;
	}
	return a;
}