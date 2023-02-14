class Solution {
public:
    bool possible(vector<int>& a, int mid, int k) {
        int n = a.size();
        vector<int> track;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) {
                track.push_back(i);
            }
        }
        int take = 0, sz = (int)track.size();
        int i = 0;
        while (i < sz) {
            int should = track[i];
            int cnt = 0;
            while (i < sz && track[i] == should) {
                ++i;
                ++cnt;
                ++should;
            }
            take += (cnt + 1) / 2;
        }
        return take >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int lo = 1, hi = 1e9;
        int ans = lo;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (possible(nums, mid, k)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};