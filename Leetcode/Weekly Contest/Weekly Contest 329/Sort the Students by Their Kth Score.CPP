class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size(), m = score[0].size();
        vector<pair<int, int>> track;
        for (int i = 0; i < n; i++) {
            track.push_back({score[i][k], i});
        }
        sort(track.begin(), track.end(), greater<pair<int, int>>());
        vector<vector<int>> ans;
        for (auto& x : track) {
            int i = x.second;
            vector<int> now;
            for (int j = 0; j < m; j++) {
                now.push_back(score[i][j]);
            }
            ans.push_back(now);
        }
        return ans;
    }
};