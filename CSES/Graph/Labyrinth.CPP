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
int vis[N][N];
Data par[N][N];
int rs, cs, re, ce;
int ok = 0;
string ans;

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
			if (c == 'B') {
				re = i;
				ce = j;
			}
			graph[i][j] = c == '#' ? 0 : 1;
		}
	}
	queue<pair<int, int>> q;
	q.push({rs, cs});
	vis[rs][cs] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (r == re && c == ce) {
			ok = 1;
			break;
		}
		int dr[] = { -1, 0, 1, 0};
		int dc[] = {0, -1, 0, 1};
		string dir = "ULDR";
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr > 0 && nr <= n && nc > 0 && nc <= m) {
				if (!vis[nr][nc] && graph[nr][nc]) {
					par[nr][nc] = Data(r, c, dir[i]);
					vis[nr][nc] = 1;
					q.push({nr, nc});
				}
			}
		}
	}
	if (!ok) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int r = re, c = ce;
	while (!(r == rs && c == cs)) {
		ans.push_back(par[r][c].dir);
		int pr = par[r][c].row;
		c = par[r][c].col;
		r = pr;
	}
	reverse(all(ans));
	cout << ans.length() << '\n';
	cout << ans;
	return 0;
