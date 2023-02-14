class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> bits(35);
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((1 << i) & nums[j]) {
                    bits[i].push_back(j);
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int mx = 1;
            for (int j = 0; j < 32; j++) {
                auto it = lower_bound(bits[j].begin(), bits[j].end(), i);
                if (it != bits[j].end()) {
                    mx = max(mx, *it - i + 1);
                }
            }
            ans[i] = mx;
        }
        return ans;
    }
};