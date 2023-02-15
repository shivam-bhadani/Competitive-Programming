class Solution {
public:
    long long getConcat(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        string s = s1 + s2;
        long long ans = 0;
        for (auto& c : s) {
            ans = 10 * ans + (c - '0');
        }
        return ans;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        long long ans = 0;
        while (i < j) {
            ans += getConcat(nums[i], nums[j]);
            ++i; --j;
        }
        if (i == j) ans += nums[i];
        return ans;
    }
};