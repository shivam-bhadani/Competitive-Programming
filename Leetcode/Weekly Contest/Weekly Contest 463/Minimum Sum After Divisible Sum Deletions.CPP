class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        const long long INF = 1e18;
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // dp[j] = min leftover for prefix length j (nums[0..j-1])
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        vector<long long> best(k, INF);
        best[0] = 0;
        for (int j = 1; j <= n; j++) {
            int mod = pref[j] % k;
            long long keep = (dp[j - 1] == INF) ? INF : dp[j - 1] + nums[j - 1];
            long long deleteOp = best[mod];
            dp[j] = min(keep, deleteOp);
            if (dp[j] < best[mod]) {
                best[mod] = dp[j];
            }
        }
        return dp[n];
    }
};
