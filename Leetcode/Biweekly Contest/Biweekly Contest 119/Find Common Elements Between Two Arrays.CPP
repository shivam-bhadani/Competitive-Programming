class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int> ans(2);
        for (auto& x : nums1) {
            if (st2.count(x)) ++ans[0];
        }
        for (auto& x : nums2) {
            if (st1.count(x)) ++ans[1];
        }
        return ans;
    }
};