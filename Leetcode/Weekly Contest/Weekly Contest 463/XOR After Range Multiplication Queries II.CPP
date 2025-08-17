class Solution {
public:
    long long expo(long long a, long long b, long long m) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b = b >> 1;
        }
        return res;
    }
    long long modInverse(long long a, long long mod) {
        return expo(a, mod - 2, mod);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int q = queries.size();
        int b = sqrt(n) + 1;
        vector<vector<vector<array<int, 3>>>> bucket(b + 1, vector<vector<array<int, 3>>>(b + 1));
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= b) {
                bucket[k][l % k].push_back({l, r, v});
            } else {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            }
        }
        for (int k = 1; k <= b; k++) {
            for (int rem = 0; rem < k; rem++) {
                vector<long long> mul(n / k + 3, 1);
                for (auto &q : bucket[k][rem]) {
                    int l = (q[0] - rem) / k;
                    int r = (q[1] - rem) / k;
                    int v = q[2];
                    mul[l] = (mul[l] * v) % MOD;
                    if (r + 1 < (int)mul.size()) {
                        mul[r + 1] = (mul[r + 1] * modInverse(v, MOD)) % MOD;
                    }
                }
                long long cur = 1;
                for (int t = 0, idx = rem; idx < n; idx += k, t++) {
                    cur = (cur * mul[t]) % MOD;
                    nums[idx] = (nums[idx] * cur) % MOD;
                }
            }
        }
        int ans = 0;
        for (auto& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
