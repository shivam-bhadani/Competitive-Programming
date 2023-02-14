class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp1, mp2, mp;
        int mn = INT_MAX;
        for (auto& x : basket1) {
            ++mp1[x];
            ++mp[x];
            mn = min(mn, x);
        }
        for (auto& x : basket2) {
            ++mp2[x];
            ++mp[x];
            mn = min(mn, x);
        }
        vector<long long> track1, track2;
        for (auto& x : mp) {
            if (x.second & 1) return -1;
            int should = x.second / 2;
            int freq1 = mp1[x.first], freq2 = mp2[x.first];
            for (int i = 0; i < should - freq1; i++) {
                track2.push_back(x.first);
            }
            for (int i = 0; i < should - freq2; i++) {
                track1.push_back(x.first);
            }
        }
        sort(track1.begin(), track1.end());
        sort(track2.begin(), track2.end(), greater<int>());
        int sz = (int)track1.size();
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += min(min(track1[i], track2[i]), 2LL * mn);
        }
        return ans;
    }
};