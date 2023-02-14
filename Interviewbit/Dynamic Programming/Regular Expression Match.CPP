// Problem Link - https://www.interviewbit.com/problems/regular-expression-match/

int Solution::isMatch(const string s, const string p) {
	int m = s.length(), n = p.length();
	vector<bool> cur(m + 1, false);
	cur[0] = true;
	for (int j = 1; j <= n; j++) {
		bool pre = cur[0]; // use the value before update
		cur[0] = cur[0] && p[j - 1] == '*';
		for (int i = 1; i <= m; i++) {
			bool temp = cur[i]; // record the value before update
			if (p[j - 1] != '*')
				cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
			else cur[i] = cur[i - 1] || cur[i];
			pre = temp;
		}
	}
	return cur[m];
}
