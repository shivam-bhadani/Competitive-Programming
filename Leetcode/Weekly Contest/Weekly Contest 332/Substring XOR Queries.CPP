class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        map<long long, pair<int, int>> mp;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                mp[0] = {i, i};
            }
            else {
                long long now = 0;
                for (int j = i; j < n && now <= 1e9; j++) {
                    now = now * 2 + (s[j] - '0');
                    mp[now] = {i, j};
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& q : queries) {
            int x = q[0] ^ q[1];
            if (mp.count(x)) {
                ans.push_back({mp[x].first, mp[x].second});
            }
            else {
                ans.push_back({ -1, -1});
            }
        }
        return ans;
    }
};