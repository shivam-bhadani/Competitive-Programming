class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = (int)s.size();
        string t(n, 'a');
        int dis = 0;
        for (int i = 0; i < n; i++) {
            dis += min(26 - abs(s[i] - t[i]), abs(s[i] - t[i]));
        }
        for (int i = n - 1; i >= 0; i--) {
            if (dis <= k) break;
            int curr = min(26 - abs(s[i] - t[i]), abs(s[i] - t[i]));
            int ok = 0;
            char put;
            for (char c = 'a'; c <= 'z'; c++) {
                int contrib = min(26 - abs(s[i] - c), abs(s[i] - c));
                int now_dis = dis - curr + contrib;
                if (now_dis <= k) {
                    ok = 1;
                    put = c;
                    break;
                }
            }
            if (ok) {
                t[i] = put;
                break;
            }
            t[i] = s[i];
            dis -= curr;
        }
        return t;
    }
};