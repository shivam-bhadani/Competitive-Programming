class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]) - nums.begin();
            ans += right - left;
        }
        return ans;
    }
};