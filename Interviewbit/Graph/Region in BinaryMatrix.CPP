// Problem Link - https://www.interviewbit.com/problems/region-in-binarymatrix/

const int N = 105;
int vis[N][N];
int ans = 0;

void dfs(int x, int y, vector<vector<int>>& a, int& now) {
	int n = a.size(), m = a[0].size();
	vis[x][y] = 1;
	now++;
	vector<int> dx = { -1, 0, 1, 0, -1, -1, 1, 1};
	vector<int> dy = {0, 1, 0, -1, -1, 1, -1, 1};
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 1 && vis[nx][ny] == 0) {
			dfs(nx, ny, a, now);
		}
	}
}

int Solution::solve(vector<vector<int> > &a) {
	int n = a.size(), m = a[0].size();
	ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			vis[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && vis[i][j] == 0) {
				int now = 0;
				dfs(i, j, a, now);
				ans = max(ans, now);
			}
		}
	}
	return ans;
}
