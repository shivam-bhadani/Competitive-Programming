// Problem Link - https://www.interviewbit.com/problems/word-ladder-ii/

set<vector<string>> ansSet;
void dfs(string& curr, string& end, int step, int k, map<string, vector<string>>& adj, vector<string>& ds) {
	if (step == k && curr == end) {
		ansSet.insert(ds);
		return;
	}
	for (auto& it : adj[curr]) {
		ds.push_back(it);
		dfs(it, end, step + 1, k, adj, ds);
		ds.pop_back();
	}
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
	ansSet.clear();
	set<string> vis;
	for (auto& x : dict) {
		vis.insert(x);
	}
	queue<pair<int, string>> q;
	q.push({1, start});
	if (vis.count(start)) {
		vis.erase(start);
	}
	map<string, vector<string>> adj;
	int ans = INT_MAX;
	map<string, int> taken;
	while (!q.empty()) {
		int step = q.front().first;
		string curr = q.front().second;
		q.pop();
		if (curr == end) {
			ans = min(ans, step);
		}
		for (int i = 0; i < curr.size(); i++) {
			string temp = curr;
			for (int c = 'a'; c <= 'z'; c++) {
				temp[i] = c;
				if (vis.count(temp) || taken[temp] >= step + 1) {
					vis.erase(temp);
					q.push({step + 1, temp});
					adj[curr].push_back(temp);
					taken[temp] = step + 1;
				}
			}
		}
	}
	vector<string> ds;
	ds.push_back(start);
	dfs(start, end, 1, ans, adj, ds);
	vector<vector<string>> finalAns;
	for (auto& x : ansSet) {
		finalAns.push_back(x);
	}
	return finalAns;
}
