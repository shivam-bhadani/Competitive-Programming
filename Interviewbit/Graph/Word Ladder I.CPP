// Problem Link - https://www.interviewbit.com/problems/word-ladder-i/

int Solution::solve(string A, string B, vector<string> &C) {
	set<string> vis;
	for (auto& x : C) {
		vis.insert(x);
	}
	if (!vis.count(B)) return -1;
	queue<pair<int, string>> q;
	q.push({1, A});
	if (vis.count(A)) {
		vis.erase(A);
	}
	while (!q.empty()) {
		int step = q.front().first;
		string curr = q.front().second;
		q.pop();
		if (curr == B) return step;
		for (int i = 0; i < curr.size(); i++) {
			string temp = curr;
			for (int c = 'a'; c <= 'z'; c++) {
				temp[i] = c;
				if (vis.count(temp)) {
					vis.erase(temp);
					q.push({step + 1, temp});
				}
			}
		}
	}
	return -1;
}
