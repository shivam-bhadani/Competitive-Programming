class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> mp;
        for (auto& x : access_times) {
            mp[x[0]].push_back(stoi(x[1]));
        }
        vector<string> ans;
        for (auto& x : mp) {
            vector<int> v = x.second;
            sort(v.begin(), v.end());
            for (int i = 2; i < (int)v.size(); i++) {
                if (v[i] - v[i - 2] < 100) {
                    ans.push_back(x.first);
                    break;
                }
            }
        }
        return ans;
    }
};