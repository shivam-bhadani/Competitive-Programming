class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        if (nums[mid] == k) {
            return 0;
        }
        if (nums[mid] < k) {
            long long ans = 0;
            for (int i = mid; i < n; i++) {
                ans += max(0LL, k * 1LL - nums[i]);
            }
            return ans;
        }
        else {
            long long ans = 0;
            for (int i = 0; i <= mid; i++) {
                ans += max(0LL, nums[i] - k * 1LL);
            }
            return ans;
        }
    }
};