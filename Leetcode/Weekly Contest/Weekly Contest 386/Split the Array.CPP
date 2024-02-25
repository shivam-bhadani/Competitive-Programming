class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for (auto& x : nums) {
            ++mp[x];
        }
        for (auto& x : mp) {
            if (x.second > 2) return false;
        }
        return true;
    }
};