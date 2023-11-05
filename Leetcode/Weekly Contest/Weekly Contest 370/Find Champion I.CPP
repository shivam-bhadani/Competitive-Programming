class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> indeg(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (grid[i][j]) {
                    ++indeg[j];
                }
                else {
                    ++indeg[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) return i;
        }
        return -1;
    }
};