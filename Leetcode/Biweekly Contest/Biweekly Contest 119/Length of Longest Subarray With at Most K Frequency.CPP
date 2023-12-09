class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = (int)nums.size(), ans = 0;
        map<int, int> mp;
        int i = 0;
        for (int j = 0; j < n; j++) {
            ++mp[nums[j]];
            while (mp[nums[j]] > k) {
                --mp[nums[i]];
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};