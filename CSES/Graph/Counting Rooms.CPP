/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1005;

int n, m;
int graph[N][N];
int vis[N][N];

void dfs(int r, int c) {
	vis[r][c] = 1;
	int dr[] = { -1, 0, 1, 0};
	int dc[] = {0, -1, 0, 1};
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 1 && nr <= n && nc >= 1 && nc <= m) {
			if (!vis[nr][nc] && graph[nr][nc]) {
				dfs(nr, nc);
			}
		}
	}
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			graph[i][j] = c == '.' ? 1 : 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && graph[i][j]) {
				++ans;
				dfs(i, j);
			}
		}
	}
	cout << ans;
}