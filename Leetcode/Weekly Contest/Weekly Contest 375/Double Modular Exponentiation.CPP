class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            auto x = variables[i];
            long long a = x[0], b = x[1], c = x[2], m = x[3];
            long long now = 1;
            while (b--) {
                now = (now * a) % 10;
            }
            long long y = now;
            now = 1;
            while (c--) {
                now = (now * y) % m;
            }
            if (now == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};