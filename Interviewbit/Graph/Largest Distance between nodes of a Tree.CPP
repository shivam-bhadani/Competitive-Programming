// Problem Link - https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

const int N = 40005;
vector<int> adj[N];
int dis[N];
int ans = 0;

void dfs(int node, int par) {
	int mx = 0;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
		mx = max(mx, dis[it]);
	}
	dis[node] = 1 + mx;
}

void dfs1(int node, int par) {
	vector<int> track;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs1(it, node);
		track.push_back(dis[it]);
	}
	sort(track.begin(), track.end());
	int now = 0;
	if (track.size()) now += track.back();
	if (track.size() >= 2) {
		track.pop_back();
		now += track.back();
	}
	ans = max(ans, now);
}

int Solution::solve(vector<int> &a) {
	int n = a.size();
	ans = 0;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		dis[i] = 0;
	}
	int root = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			root = i;
		}
		else {
			adj[i].push_back(a[i]);
			adj[a[i]].push_back(i);
		}
	}
	dfs(root, -1);
	dfs1(root, -1);
	return ans;
}
