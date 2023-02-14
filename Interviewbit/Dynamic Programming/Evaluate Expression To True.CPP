// Problem Link - https://www.interviewbit.com/problems/evaluate-expression-to-true/

int dp[201][201][2];

int solve(string& s, int i, int j, int istrue) {
	if (i > j) {
		return dp[i][j][istrue] = 0;
	}
	if (i == j) {
		if (istrue) {
			return s[i] == 'T' ? 1 : 0;
		}
		else {
			return s[i] == 'F' ? 1 : 0;
		}
	}
	if (dp[i][j][istrue] != -1) {
		return dp[i][j][istrue];
	}
	int ans = 0;
	for (int k = i + 1; k <= j - 1; k += 2) {
		if (s[k] != '&' && s[k] != '|' && s[k] != '^') continue;

		int lT = solve(s, i, k - 1, true);
		int lF = solve(s, i, k - 1, false);
		int rT = solve(s, k + 1, j, true);
		int rF = solve(s, k + 1, j, false);

		if (s[k] == '&') {
			if (istrue) {
				ans += (lT * rT);
			}
			else {
				ans += (lT * rF) + (lF * rT) + (rF * lF);
			}
		}
		else if (s[k] == '|') {
			if (istrue) {
				ans += (lT * rF) + (lF * rT) + (lT * rT);
			}
			else {
				ans += (lF * rF);
			}
		}
		else if (s[k] == '^') {
			if (istrue) {
				ans += (lF * rT) + (lT * rF);
			}
			else {
				ans += (lT * rT) + (lF * rF);
			}
		}
	}
	return dp[i][j][istrue] = ans % 1003;
}

int Solution::cnttrue(string a) {
	memset(dp, -1, sizeof(dp));
	return solve(a, 0, a.size() - 1, 1);
}
