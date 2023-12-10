class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> prefSum(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) ++prefSum[i];
            if (i) prefSum[i] += prefSum[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int from = n;
            int lo = i, hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int now = i - 1 >= 0 ? prefSum[mid] - prefSum[i - 1] : prefSum[mid];
                if (now >= k) {
                    from = mid;
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            int to = n - 1;
            ans += (to - from + 1);
        }
        return ans;
    }
};