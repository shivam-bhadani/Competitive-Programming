class Solution {
public:
    int solve(vector<int> a, vector<int> b, int x, int y) {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > x) {
                ++ans;
                swap(a[i], b[i]);
            }
            else if (b[i] > y) {
                swap(a[i], b[i]);
                ++ans;
            }
            if (a[i] > x) {
                return 1e9;
            }
            if (b[i] > y) {
                return 1e9;
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans1 = 1 + solve(nums1, nums2, nums2[n - 1], nums1[n - 1]);
        int ans2 = solve(nums1, nums2, nums1[n - 1], nums2[n - 1]);
        int ans = min(ans1, ans2);
        return (ans > 1e5 ? -1 : ans);
    }
};