class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n) {
                ans.push_back(nums[i + 1]);
                ans.push_back(nums[i]);
            }
            else {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};