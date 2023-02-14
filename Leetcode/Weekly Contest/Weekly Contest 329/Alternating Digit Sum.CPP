class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                ans += (s[i] - '0');
            }
            else {
                ans -= (s[i] - '0');
            }
        }
        return ans;
    }
};