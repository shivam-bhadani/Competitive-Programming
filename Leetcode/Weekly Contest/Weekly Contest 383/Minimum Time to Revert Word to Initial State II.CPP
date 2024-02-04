class Solution {
public:
    vector<int> z_function(const string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int ans = (n + k - 1) / k;
        vector<int> z = z_function(word);
        for (int i = 1; i <= n / k; i++) {
            int i1 = i * k;
            if (i1 < n && i1 + z[i1] == n) {
                return i;
            }
        }
        return ans;
    }
};