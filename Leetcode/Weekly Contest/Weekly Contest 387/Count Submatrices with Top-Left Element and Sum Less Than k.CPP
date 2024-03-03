class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> pref(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pref[i][j] += pref[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pref[i][j] <= k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};