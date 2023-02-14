// Problem Link - https://www.interviewbit.com/problems/commutable-islands/

// finding minimum spanning tree

int Solution::solve(int n, vector<vector<int> > &B) {
	vector<pair<int, int>> adj[n + 5];
	for (auto& x : B) {
		adj[x[0]].push_back({x[1], x[2]});
		adj[x[1]].push_back({x[0], x[2]});
	}
	vector<int> mst(n + 5), key(n + 5, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	while (!pq.empty()) {
		int node = pq.top().second;
		mst[node] = 1;
		pq.pop();
		for (auto& it : adj[node]) {
			int nxt_node = it.first;
			int dis = it.second;
			if (mst[nxt_node] == 0 && key[nxt_node] > dis) {
				pq.push({dis, nxt_node});
				key[nxt_node] = dis;
			}
		}
		while (!pq.empty() && mst[pq.top().second]) pq.pop();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (key[i] != INT_MAX)
			ans += key[i];
	}
	return ans;
}
