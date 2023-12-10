class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int sub = 0, ans = 0;
        for (auto& x : batteryPercentages) {
            if (x - sub > 0) {
                ++ans;
                ++sub;
            }
        }
        return ans;
    }
};