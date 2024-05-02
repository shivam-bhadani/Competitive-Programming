/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int INF = 1e9;
const int N = 1005;

struct Data {
	int row;
	int col;
	char dir;
	Data() {}
	Data(int _row, int _col, char _dir) {
		row = _row;
		col = _col;
		dir = _dir;
	}
};

int n, m;
int graph[N][N];
int dis[N][N];
Data par[N][N];
int rs, cs, re, ce;
int ok = 0;
string ans;

void bfs1() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 1) {
				q.push({i, j});
			}
		}
	}
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		int dr[] = { -1, 0, 1, 0};
		int dc[] = {0, -1, 0, 1};
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr > 0 && nr <= n && nc > 0 && nc <= m) {
				if (graph[nr][nc] == INF) {
					graph[nr][nc] = graph[r][c] + 1;
					q.push({nr, nc});
				}
			}
		}
	}
}

int bfs2() {
	queue<pair<int, int>> q;
	q.push({rs, cs});
	dis[rs][cs] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		if (r == 1 || r == n || c == 1 || c == m) {
			re = r;
			ce = c;
			return 1;
		}
		int nxtDis = dis[r][c] + 1;
		q.pop();
		int dr[] = { -1, 0, 1, 0};
		int dc[] = {0, -1, 0, 1};
		string dir = "ULDR";
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr > 0 && nr <= n && nc > 0 && nc <= m) {
				if (graph[nr][nc] != -1 && !dis[nr][nc] && nxtDis < graph[nr][nc]) {
					par[nr][nc] = Data(r, c, dir[i]);
					dis[nr][nc] = nxtDis;
					q.push({nr, nc});
				}
			}
		}
	}
	return 0;
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'A') {
				rs = i;
				cs = j;
			}
			if (c == '#') {
				graph[i][j] = -1;
			}
			else if (c == 'M') {
				graph[i][j] = 1;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}
	bfs1();
	if (!bfs2()) {
		cout << "NO\n";
		return 0;
	}
	int r = re;
	int c = ce;
	while (!(r == rs && c == cs)) {
		ans.push_back(par[r][c].dir);
		int pr = par[r][c].row;
		c = par[r][c].col;
		r = pr;
	}
	cout << "YES\n";
	reverse(all(ans));
	cout << (int)ans.size() << '\n';
	cout << ans;
	return 0;
}