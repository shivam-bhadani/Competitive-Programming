// Problem Link - https://www.interviewbit.com/problems/trailing-zeroes/

int Solution::solve(int A) {
	int cnt = 0;
	while (A) {
		if (A & 1) break;
		A >>= 1;
		cnt++;
	}
	return cnt;
}
