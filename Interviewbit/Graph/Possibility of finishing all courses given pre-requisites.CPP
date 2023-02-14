// Problem Link - https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

int Solution::solve(int n, vector<int> &B, vector<int> &C) {
    vector<int> adj[n + 5];
    for (int i = 0; i < B.size(); i++) {
        adj[B[i]].push_back(C[i]);
    }
    vector<int> indeg(n + 5);
    for (int i = 1; i <= n; i++) {
        for (auto& it : adj[i]) {
            indeg[it]++;
        }
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto& it : adj[node]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                q.push(it);
            }
        }
    }
    return cnt == n;
}
