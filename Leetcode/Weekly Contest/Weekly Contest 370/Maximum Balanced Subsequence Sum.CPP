class Solution {
public:
    class SegTree {
    public:
        vector<long long> segs;
        long long size = 0;
        long long ID = 0;

        SegTree(long long sz) {
            segs.assign(2 * sz, ID);
            size = sz;
        }

        long long comb(long long a, long long b) {
            return max(a, b);
        }

        void upd(long long idx, long long val) {
            segs[idx += size] = val;
            for (idx >>= 1; idx; idx >>= 1) segs[idx] = comb(segs[idx << 1], segs[idx << 1 | 1]);
        }

        long long query(long long l, long long r) {
            long long lans = ID, rans = ID;
            for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) lans = comb(lans, segs[l++]);
                if (r & 1) rans = comb(segs[--r], rans);
            }
            return comb(lans, rans);
        }
    };
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long, long long>> track;
        for (int i = 0; i < n; i++) {
            track.push_back({nums[i] - i, i});
        }
        sort(track.begin(), track.end());
        SegTree st(n + 5);
        long long ans = nums[0];
        for (auto& x : track) {
            int ind = x.second;
            long long now = max((long long)nums[ind], nums[ind] + st.query(0, ind - 1));
            st.upd(ind, now);
            ans = max(ans, now);
        }
        return ans;
    }
};