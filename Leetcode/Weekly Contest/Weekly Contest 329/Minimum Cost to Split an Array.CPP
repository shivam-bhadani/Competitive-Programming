class Solution {
public:
    int minCost(vector<int>& a, int k) {
        int n = a.size();
        set<int> st(a.begin(), a.end());
        map<int, int> mpp;
        int put = 0;
        for (auto& x : st) {
            mpp[x] = put++;
        }
        vector<int> nums;
        for (auto& x : a) {
            nums.push_back(mpp[x]);
        }
        vector<int> dp(n + 5, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> mp(n + 5);
            int cnt = 0;
            int one = 0;
            for (int j = i; j >= 1; j--) {
                cnt -= mp[nums[j - 1]];
                ++mp[nums[j - 1]];
                cnt += mp[nums[j - 1]];
                if (mp[nums[j - 1]] == 1) {
                    ++one;
                }
                if (mp[nums[j - 1]] == 2) {
                    --one;
                }
                dp[i] = min(dp[i], dp[j - 1] + cnt - one + k);
            }
        }
        return dp[n];
    }
};