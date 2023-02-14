// Problem Link - https://www.interviewbit.com/problems/snake-ladder-problem/

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
	vector<int> lad(105), snake(105);
	for (auto& x : A) {
		lad[x[0]] = x[1];
	}
	for (auto& x : B) {
		snake[x[0]] = x[1];
	}
	queue<pair<int, int>> q;
	vector<int> vis(105);
	q.push({0, 1});
	vis[1] = 1;
	int ans = INT_MAX;
	while (!q.empty()) {
		int curr = q.front().second;
		int steps = q.front().first;
		q.pop();
		if (curr == 100) {
			ans = min(ans, steps);
		}
		else {
			for (int die = 1; die <= 6; die++) {
				int nxt = curr + die;
				if (nxt <= 100 && vis[nxt] == 0) {
					if (lad[nxt] != 0) nxt = lad[nxt];
					if (snake[nxt] != 0) nxt = snake[nxt];
					if (vis[nxt] == 0) {
						q.push({steps + 1, nxt});
						vis[nxt] = 1;
					}
				}
			}
		}
	}
	return (ans == INT_MAX ? -1 : ans);
}
