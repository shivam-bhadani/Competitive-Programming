class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int ans = 0, n = (int)a.size();
        for (int i = 0; i < n; i++) {
            int cnt_inc = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j - 1] < a[j]) {
                    ++cnt_inc;
                }
                else break;
            }
            ans = max(ans, cnt_inc);
            int cnt_dec = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j - 1] > a[j]) {
                    ++cnt_dec;
                }
                else break;
            }
            ans = max(ans, cnt_dec);
        }
        return ans;
    }
};