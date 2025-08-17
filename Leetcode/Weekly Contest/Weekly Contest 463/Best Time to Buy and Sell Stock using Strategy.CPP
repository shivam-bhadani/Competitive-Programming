class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = (int)prices.size();
        vector<long long> pref1(n + 5), pref2(n + 5);
        for (int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + (strategy[i] * prices[i]);
            pref2[i + 1] = pref2[i] + prices[i];
        }
        long long ans = pref1[n];
        for (int i = 1; i + k - 1 <= n; i++) {
            int till = i + k - 1;
            long long now = pref1[i - 1];
            now += pref2[till] - pref2[i + (k / 2) - 1];
            now += pref1[n] - pref1[till];
            ans = max(ans, now);
        }
        return ans;
    }
};