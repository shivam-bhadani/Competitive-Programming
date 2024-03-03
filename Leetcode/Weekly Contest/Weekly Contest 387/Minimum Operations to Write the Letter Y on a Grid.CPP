class Solution {
public:
    int calcAns(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int mid = n / 2, ans = 0;
        vector<vector<int>> done(n, vector<int>(n));
        int i = 0, j = 0;
        while (i <= mid) {
            if (grid[i][j] != x) {
                ++ans;
            }
            done[i][j] = 1;
            ++i;
            ++j;
        }
        i = 0, j = n - 1;
        while (i < mid) {
            if (grid[i][j] != x) {
                ++ans;
            }
            done[i][j] = 1;
            ++i;
            --j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (done[i][j]) continue;
                else if (i >= mid && j == mid) {
                    if (grid[i][j] != x) {
                        ++ans;
                    }
                }
                else {
                    if (grid[i][j] != y) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = n * n;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (i != j) {
                    ans = min(ans, calcAns(grid, i, j));
                }
            }
        }
        return ans;
    }
};