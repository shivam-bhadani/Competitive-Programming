class Solution {
public:
    map<vector<int>, int> cache;
    int dp(int i, int jump, int op1, int k) {
        if(cache.count({i, jump, op1})) {
            return cache[{i, jump, op1}];
        }
        int ans = (i == k);
        if(op1 == 0) {
            ans += dp(i - 1, jump, 1, k);
        }
        if(i + (1 << jump) <= k + 1) {
            ans += dp(i + (1 << jump), jump + 1, 0, k);
        }
        return cache[{i, jump, op1}] = ans;
    }
    int waysToReachStair(int k) {
        return dp(1, 0, 0, k);
    }
};