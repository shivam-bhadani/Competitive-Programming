class Solution {
public:
    class DSU
    {
    private:
        vector<int> parent, size;
    public:
        DSU(int n)
        {
            for (int i = 0; i <= n; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }
        int getPar(int node)
        {
            if (parent[node] == node)
                return node;
            return parent[node] = getPar(parent[node]);
        }
        void unite(int u, int v)
        {
            int pu = getPar(u);
            int pv = getPar(v);
            if (pu == pv)
                return;
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
        int siz(int n)
        {
            int p = getPar(n);
            return size[p];
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU ds(n + 5);
        for (auto& x : edges) {
            ds.unite(x[0], x[1]);
        }
        map<int, int> par_sum;
        for (auto& x : edges) {
            int par = ds.getPar(x[0]);
            if (par_sum.count(par)) {
                par_sum[par] &= x[2];
            }
            else {
                par_sum[par] = x[2];
            }
        }
        vector<int> ans;
        for (auto& x : query) {
            if (x[0] == x[1]) {
                ans.push_back(0);
            }
            else if (ds.getPar(x[0]) != ds.getPar(x[1])) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(par_sum[ds.getPar(x[0])]);
            }
        }
        return ans;
    }
};