// Problem Link - https://www.interviewbit.com/problems/delete-edge/

const int N = 100005;
const int MOD = 1e9 + 7;
long long sum[N];
vector<int> adj[N];
long long ans = 0;

void dfs(int node, int par, vector<int>& a) {
    sum[node] = a[node - 1];
    for (auto& it : adj[node]) {
        if (it == par) continue;
        dfs(it, node, a);
        sum[node] = (sum[node] + sum[it]);
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    ans = 0;
    for (int i = 0; i <= n + 1; i++) {
        sum[i] = 0;
        adj[i].clear();
    }
    for (auto& x : B) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    dfs(1, -1, A);
    for (int i = 2; i <= n; i++) {
        long long part1 = sum[i];
        long long part2 = sum[1] - sum[i];
        ans = max(ans, (part1 * part2) % MOD);
    }
    return ans;
}
