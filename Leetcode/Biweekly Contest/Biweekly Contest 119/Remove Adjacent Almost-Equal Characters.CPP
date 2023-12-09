class Solution {
public:
    int cache[105][30];
    int dp(int n, string& word, int ch) {
        if (n == 0) {
            return 0;
        }
        if (cache[n][ch] != -1) {
            return cache[n][ch];
        }
        int ans = 1e5;
        for (int i = 0; i < 26; i++) {
            if (abs(ch - i) <= 1) continue;
            ans = min(ans, dp(n - 1, word, i));
        }
        if (word[n - 1] != ch + 'a') ++ans;
        return cache[n][ch] = ans;
    }
    int removeAlmostEqualCharacters(string word) {
        memset(cache, -1, sizeof cache);
        int ans = 1e5;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, dp(word.size(), word, i));
        }
        return ans;
    }
};