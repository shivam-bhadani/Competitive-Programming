class Solution {
public:
    int minimumScore(string s, string t) {
        int nt = t.size(), ns = s.size();
        int rt = nt - 1, rs = ns - 1;
        vector<int> rght(nt);
        while (rt >= 0 && rs >= 0) {
            if (t[rt] == s[rs]) {
                rght[rt] = rs;
                rt--;
                rs--;
            }
            else {
                rs--;
            }
        }
        if (rt == -1) return 0;
        ++rt;
        int ans = rt;
        int lt = 0, ls = 0;
        while (lt < nt && ls < ns) {
            if (t[lt] == s[ls]) {
                int r = upper_bound(rght.begin() + rt, rght.end(), ls) - rght.begin();
                ans = min(ans, r - lt - 1);
                ++lt;
                ++ls;
            }
            else {
                ++ls;
            }
        }
        return ans;
    }
};