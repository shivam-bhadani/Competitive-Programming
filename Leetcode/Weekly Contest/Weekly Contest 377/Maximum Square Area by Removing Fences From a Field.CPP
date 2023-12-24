class Solution {
public:
    int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        vector<int> ht;
        ht.push_back(1);
        for (auto& x : hFences) ht.push_back(x);
        ht.push_back(m);
        vector<int> vt;
        vt.push_back(1);
        for (auto& x : vFences) vt.push_back(x);
        vt.push_back(n);
        map<int, int> mp;
        for (int i = 0; i < ht.size(); i++) {
            for (int j = i + 1; j < ht.size(); j++) {
                ++mp[ht[j] - ht[i]];
            }
        }
        long long ans = -1;
        for (int i = 0; i < (int)vt.size(); i++) {
            for (int j = i + 1; j < (int)vt.size(); j++) {
                long long x = vt[j] - vt[i];
                if (mp.count(x)) {
                    ans = max(ans, x * x);
                }
            }
        }
        return ans % MOD;
    }
};