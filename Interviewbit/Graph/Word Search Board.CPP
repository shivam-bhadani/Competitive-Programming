// Problem Link - interviewbit.com/problems/word-search-board/

vector<string>m;
string v;
bool ok;
int n, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(int i, int x, int y) {
	if (ok)return;
	if (i == v.size()) {
		ok = true;
		return;
	}
	for (int j = 0; j < 4; j++) {
		if (x + dx[j] >= n || x + dx[j] < 0 || y + dy[j] >= c || y + dy[j] < 0)continue;
		if (m[x + dx[j]][y + dy[j]] == v[i]) solve(i + 1, x + dx[j], y + dy[j]);
	}
}

int Solution::exist(vector<string> &A, string B) {
	ok = false;
	n = A.size();
	c = A[0].size();
	m = A;
	v = B;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			if (A[i][j] == v[0])
				solve(1, i, j);
		}
	}
	return ok;
}