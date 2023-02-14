// Problem Link - https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string s) {
	int open = 0, close = 0;
	for (auto& c : s) {
		if (c == '(') open++;
		else {
			if (open) open--;
			else return false;
		}
	}
	return open == 0;
}
