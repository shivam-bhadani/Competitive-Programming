class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0;
        for (auto& x : transactions) {
            ans = max(ans, (long long)min(x[0], x[1]));
        }
        for (auto& x : transactions) {
            ans += max(0LL, (long long)x[0] - x[1]);
        }
        return ans;
    }
};