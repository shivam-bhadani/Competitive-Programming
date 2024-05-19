class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        for(int i=0; i<30; i++) {
            map<long long, long long> mp;
            for(auto& x: nums) {
                if(x) {
                    ++mp[x%10];
                    x /= 10;
                }
            }
            vector<long long> v;
            for(auto& x: mp) {
                v.push_back(x.second);
            }
            if(v.empty()) break;
            long long prefSum = v[0], now = 0;
            for(int i=1; i<(int)v.size(); i++) {
                now += v[i] * prefSum;
                prefSum += v[i];
            }
            ans += now;
        }
        return ans;
    }
};