class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n);
        map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            mp[nums[i]] = max(mp[nums[i]], i);
            prefMax[i] = mp[nums[i]];
        }
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], prefMax[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (prefMax[i] == i) {
                ++cnt;
            }
        }
        long long ans = 0, prev = 1;
        while (cnt--) {
            ans = prev;
            prev = (prev + ans) % MOD;
        }
        return ans;
    }
};