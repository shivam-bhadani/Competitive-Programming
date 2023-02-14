// Problem Link - https://www.interviewbit.com/problems/black-shapes/

void dfs(int x, int y, vector<string>& a) {
	int n = a.size(), m = a[0].size();
	a[x][y] = 'O';
	vector<int> dx = { -1, 0, 1, 0};
	vector<int> dy = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 'X') {
			dfs(nx, ny, a);
		}
	}
}

int Solution::black(vector<string> &a) {
	int n = a.size(), m = a[0].size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X') {
				dfs(i, j, a);
				ans++;
			}
		}
	}
	return ans;
}
