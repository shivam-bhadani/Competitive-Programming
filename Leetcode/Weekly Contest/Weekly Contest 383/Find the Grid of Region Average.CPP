class Solution {
public:
    int check(vector<vector<int>>& track, int t) {
        vector<int> dx = { -1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (ii >= 0 && ii < 3 && jj >= 0 && jj < 3) {
                        if (abs(track[i][j] - track[ii][jj]) > t) {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> cnt(n, vector<int>(m));
        vector<vector<int>> sum(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 2 < n && j + 2 < m) {
                    vector<vector<int>> track(3, vector<int>(3));
                    int sum_now = 0;
                    for (int k = i; k <= i + 2; k++) {
                        for (int l = j; l <= j + 2; l++) {
                            track[k - i][l - j] = image[k][l];
                            sum_now += image[k][l];
                        }
                    }
                    if (check(track, threshold)) {
                        for (int k = i; k <= i + 2; k++) {
                            for (int l = j; l <= j + 2; l++) {
                                sum[k][l] += sum_now / 9;
                                ++cnt[k][l];
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt[i][j] == 0) {
                    ans[i][j] = image[i][j];
                }
                else {
                    ans[i][j] = sum[i][j] / cnt[i][j];
                }
            }
        }
        return ans;
    }
};