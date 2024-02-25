class Solution {
public:
    int possible(int mid, vector<int>& nums, vector<int>& chng) {
        int n = nums.size();
        vector<int> last(n + 1);
        for (int i = 0; i < mid; i++) {
            last[chng[i]] = i + 1;
        }
        vector<pair<int, int>> track;
        for (int i = 1; i <= n; i++) {
            if (last[i] == 0) return 0;
            track.push_back({last[i], i});
        }
        sort(track.begin(), track.end());
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int ind = track[i].second - 1;
            int op = track[i].first - 1 - sum - i;
            if (op >= nums[ind]) {
                sum += nums[ind];
            }
            else return 0;
        }
        return 1;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();
        int lo = 1, hi = m;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (possible(mid, nums, changeIndices)) {
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