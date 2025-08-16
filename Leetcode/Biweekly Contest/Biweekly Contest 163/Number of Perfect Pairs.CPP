class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<long long> pos, neg;
        long long z = 0;
        for (auto& x : nums) {
            if (x > 0) pos.push_back(x);
            else if (x < 0) neg.push_back(-x);
            else z++;
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        long long ans = 0;
        ans += sameSignAns(pos);
        ans += sameSignAns(neg);
        ans += oppSignAns(pos, neg);
        ans += z * (z - 1) / 2;
        return ans;
    }

    long long sameSignAns(vector<long long>& a) {
        long long cnt = 0;
        int n = (int)a.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && a[j] < (a[i] + 1) / 2) j++;
            cnt += (i - j);
        }
        return cnt;
    }

    long long oppSignAns(vector<long long>& pos, vector<long long>& neg) {
        long long cnt = 0;
        // |a + (-b)| = |a - b| <= min(a, b)
        for (long long x : pos) {
            auto lo = (x + 1) / 2;
            auto hi = x * 2;
            auto it1 = lower_bound(neg.begin(), neg.end(), lo);
            auto it2 = upper_bound(neg.begin(), neg.end(), hi);
            cnt += (it2 - it1);
        }
        return cnt;
    }
};
